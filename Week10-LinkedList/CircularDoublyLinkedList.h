#pragma once

#include <stdexcept>

using namespace std;

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

	// O(1)
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
	CircularDoublyLinkedList() {
		dummyNode = new Node<T>(T(), nullptr, nullptr);
		dummyNode->next = dummyNode;
		dummyNode->previous = dummyNode;
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
			throw logic_error("list is empty");
		}
		return remove(dummyNode->previous);
	}

	// O(1)
	T pop_first() {
		if (numberOfItems == 0) {
			throw logic_error("list is empty");
		}
		return remove(dummyNode->next);
	}

	// O(1)
	int size() {
		return numberOfItems;
	}

	// O(n)
	void print_forward() {
		Node<T>* currentNode = dummyNode->next;
		while (currentNode != dummyNode) {
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}

	// O(n)
	void print_backwards() {
		Node<T>* currentNode = dummyNode->previous;
		while (currentNode != dummyNode) {
			cout << currentNode->data << " ";
			currentNode = currentNode->previous;
		}
		cout << endl;
	}

	// O(n)
	T at(int index) {
		if (index >= numberOfItems) {
			throw length_error("invalid index");
		}
		Node<T>* currentNode = dummyNode->next;
		for ( int currentIndex = 0; currentIndex < index; currentIndex++){

			currentNode = currentNode->next;
		}
		return currentNode->data;
	}

	// O(n)
	T set(int index, T value) {
		if (index >= numberOfItems) {
			throw length_error("invalid index");
		}
		Node<T>* currentNode = dummyNode->next;
		for (int currentIndex = 0; currentIndex < index; currentIndex++) {

			currentNode = currentNode->next;
		}
		auto oldData = currentNode->data;
		currentNode->data = value;
		return oldData;
	}

};