#pragma once
#include <sstream>
#include <string>


template <typename T>
struct QueueItem {
	QueueItem* prev;
	T data;
	QueueItem* next;
};


template <typename T>
class Queue {
private:
	size_t size, max_size;
	QueueItem<T>* head;
	QueueItem<T>* tail;

public:
	Queue(size_t queue_size) {
		max_size = queue_size;
		size = 0;
		head = tail = nullptr;
	}

	size_t getMaxSize() {
		return max_size;
	}

	size_t getSize() {
		return size;
	}

	bool isEmpty() {
		return getSize() == 0;
	}

	bool isFull() {
		return getSize() == getMaxSize();
	}

	std::string toString() {
		std::stringstream buffer;
		buffer << "{ ";
		for (QueueItem<T>* pointer = head; pointer != nullptr; pointer = pointer->next) {
			buffer << pointer->data << " ";
		}
		buffer << "}";
		return buffer.str();
	}

	void push(T value) {
		if (isFull()) {
			throw std::out_of_range("can't push elements in full queue");
		}
		QueueItem<T>* item = new QueueItem<T>;
		item->data = value;
		item->prev = nullptr;
		item->next = head;
		if (isEmpty()) {
			tail = item;
		}
		else {
			head->prev = item;
		}
		head = item;
		size++;
	}

	T pop() {
		if (isEmpty()) {
			throw std::out_of_range("can't pop elements from empty queue");
		}
		QueueItem<T>* pop_item = tail;
		tail = tail->prev;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		size--;
		T value = pop_item->data;
		delete pop_item;
		return value;
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}
};
