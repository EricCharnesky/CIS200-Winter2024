#pragma once

template <typename T>
class LinkedList {

private:
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* next;
		Node<T>* previous;

		Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr) {
			this->data = data;
			this->next = next;
			this->previous = previous;
		}
	};

	Node<T>* first;
	Node<T>* last;
	int numberOfItems;

	

public:
	LinkedList(T data) {
		this->first = new Node<T>(data);
		this->last = first;
		numberOfItems = 1;
	}

	// O(1)
	void add_item(T item) {
		this->last->next = new Node<T>(item, nullptr, this->last);
		this->last = this->last->next;
		numberOfItems++;
	}

	// O(1)
	T pop() {
		T item = last->data;
		auto oldLast = last;
		last = last->previous;
		if (last != nullptr) {
			last->next = nullptr;
		}
		
		if (last == first) {
			first = nullptr;
		}
		delete oldLast;
		numberOfItems--;
		return item;
	}

	// O(1)
	int size() {
		return numberOfItems;
	}

};