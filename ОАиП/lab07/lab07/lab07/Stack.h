#pragma once
#include <fstream>
#include <string>
#include <sstream>


template <typename T>
struct StackItem {
	T data;
	StackItem<T>* next;
};


template <typename T>
class Stack {
private:
	StackItem<T>* head = nullptr;

public:
	bool isEmpty() {
		return head == nullptr;
	}

	std::string toString() {
		std::stringstream buffer;
		buffer << "{ ";
		for (StackItem<T>* pointer = head; pointer != nullptr; pointer = pointer->next) {
			buffer << pointer->data << ' ';
		}
		buffer << "}";
		return buffer.str();
	}

	T pop() {
		if (isEmpty()) {
			throw std::out_of_range("pop from empty stack");
		}
		StackItem<T>* pointer = head;
		T value = pointer->data;
		head = head->next;
		delete pointer;
		return value;
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(T value) {
		StackItem<T>* item = new StackItem<T>;
		item->data = value;
		item->next = head;
		head = item;
	}
};
