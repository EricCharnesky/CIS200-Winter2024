#pragma once

#include <vector>

using namespace std;

template <typename T>
class Queue {
private:
	int frontIndex;
	int backIndex;
	int currentSize;
	T[] items;

	// make bigger array and move everything
	// reset back and front index
	void resize() {

	}
public:

	Queue() {
		frontIndex = 0;
		backIndex = 0;
		currentSize = 10;
		items = new T[currentSize];
	}

	// average O(1)
	void enqueue(T item) {
		items[backIndex] = item;
		backIndex++;
		backIndex %= currentSize;

		if (backIndex == frontIndex) {
			resize();
		}
	}

	// O(1)
	T front() {
		return items.at(frontIndex);
	}

	// using a vector gives fast performance
	// for using more memory
	// O(1)
	T dequeue() {
		T item = items.at(frontIndex);

		frontIndex++;

		return item;
	}
};