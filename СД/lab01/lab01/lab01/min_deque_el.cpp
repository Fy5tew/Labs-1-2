#include <iostream>
#include <deque>
#include "funcs.h"
using namespace std;


int get_min(deque<int> deq) {
	int min = 20;
	for (int v : deq) {
		if (v < min) {
			min = v;
		}
	}
	return min;
}


void min_deque_el() {
	deque<int> deq = { 3, 5, 2, 6, 8, 2, 1, 6, 3 };
	int min = get_min(deq);

	cout << "Изначальная очередь: "; print(deq); cout << endl;
	cout << "Минимальный элемент: " << min << endl;

	deq.push_front(min);
	cout << "Очередь после вставки: "; print(deq); cout << endl;
}
