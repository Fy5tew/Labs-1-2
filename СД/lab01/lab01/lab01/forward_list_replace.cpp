#include <iostream>
#include <forward_list>
#include "funcs.h"
using namespace std;


void forward_list_replace() {
	forward_list<int> lst = { 1, 5, 3, 4, 2, 6, 7, 4 };
	cout << "�������� ������: "; print(lst); cout << endl;

	int n;
	cout << "������� ���������� �������� ��� ������: "; cin >> n;

	lst.clear();
	lst.push_front(9);
	auto it = lst.begin();
	lst.insert_after(it, n-1, 9);

	cout << "������ ����� ���������: "; print(lst); cout << endl;
}
