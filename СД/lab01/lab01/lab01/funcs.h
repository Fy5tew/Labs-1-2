#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;


template <typename T>
void print(list<T> lst) {
	cout << "{ ";
	for (auto v : lst) {
		cout << v << " ";
	}
	cout << "}";
}


template <typename T>
void print(vector<T> vec) {
	cout << "{ ";
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << "}";
}


template <typename T>
void print(deque<T> deq) {
	cout << "{ ";
	for (auto v : deq) {
		cout << v << " ";
	}
	cout << "}";
}


template <typename T>
void print(forward_list<T> lst) {
	cout << "{ ";
	for (auto v : lst) {
		cout << v << " ";
	}
	cout << "}";
}
