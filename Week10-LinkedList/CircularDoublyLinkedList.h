#pragma once

#include <stdexcept>

template <typename T>
class CircularDoublyLinkedList {

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

	Node<T>* dummyNode;
	int numberOfItems;

	void addBetween(T data, Node<T>* next, Node<T>* previous) {
		Node<T>* newNode = new Node<T>(data, next, previous);
		newNode->next->previous = newNode;
		newNode->previous->next = newNode;
		numberOfItems++;
	}

	T remove(Node<T>* node) {
		T data = node->data;
		node->previous->next = node->next;
		node->next->previous = node->previous;
		delete node;
		numberOfItems--;
		return data;
	}



public:
	LinkedList() {
		dummyNode = new Node<T>(T(), nullptr, nullptr);
		dummyNode->next = dummyNode;
		dummyNode->previous  dummyNode;
		numberOfItems = 0;
	}

	// O(1)
	void add_last(T item) {
		addBetween(item, dummyNode, dummyNode->previous);
	}

	// O(1)
	void add_first(T item) {
		addBetween(item, dummyNode->next, dummyNode);
	}

	// O(1)
	T pop_last() {
		if (numberOfItems == 0) {
			throw runtime_error("list is empty");
		}
		return remove(dummyNode->previous);
	}

	// O(1)
	T pop_first() {
		if (numberOfItems == 0) {
			throw runtime_error("list is empty");
		}
		return remove(dummyNode->next);
	}

	// O(1)
	int size() {
		return numberOfItems;
	}

};