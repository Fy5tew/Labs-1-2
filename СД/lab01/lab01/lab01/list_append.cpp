#include <iostream>
#include <list>
#include "funcs.h"
using namespace std;


void list_append() {
	list<int> lst = { 1, 2, 3, 4, 5 };
	cout << "Исходный список: "; print(lst); cout << endl;
	
	int append_count;
	cout << "Введите количество элементов для вставки: "; cin >> append_count;

	for (int i = 0; i < append_count; i++) {
		lst.push_front(7);
	}

	cout << "Список после вставки: "; print(lst); cout << endl;
}