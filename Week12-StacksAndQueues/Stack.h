#pragma once

#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> items;
public:
	Stack() {

	}


	// using a linked list would give worst case O(1)
	// average O(1)
	void push(T item) {
		items.push_back(item);
	}

	// O(1)
	T peek() {
		return items.at(items.size() - 1);
	}

	// using a linked list would give worst case O(1)
	// average O(1)
	T pop() {
		T item = items.at(items.size() - 1);
		items.erase(items.end() - 1);
		return item;
	}

	bool isEmpty() {
		return items.size() == 0;
	}
};