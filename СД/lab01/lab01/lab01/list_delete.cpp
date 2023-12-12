#include <iostream>
#include <list>
#include "funcs.h"
using namespace std;


void list_delete() {
	list<int> lst = { 4, 5, 6, 2, 7, 8, 3, 5, 7 };
	cout << "Исходный список: "; print(lst); cout << endl;

	int to_delete;
	cout << "Введите индекс элемента для удаления: "; cin >> to_delete;

	auto it = lst.begin();
	int i = 0;
	int delete_value;
	for (auto v : lst) {
		delete_value = v;
		if (i == to_delete) {
			break;
		}
		it++; i++;
	}
	lst.erase(it);
	lst.push_front(delete_value);

	cout << "Список после изменений: "; print(lst); cout << endl;
}
