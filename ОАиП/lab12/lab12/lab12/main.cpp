#include "Heap.h"
#include <iostream>
using namespace std;

#define MAX_SIZE 30

heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------

heap::Heap unionHeap(heap::Heap heapA, heap::Heap heapB)
{
	int max_size = heapA.maxSize + heapB.maxSize;
	heap::Heap heapC = heap::create(max_size, cmpAAA);

	for (int i = 0; i < heapA.size; i++) {
		AAA* heap_element = (AAA*)(heapA.storage[i]);
		AAA* new_element = new AAA;
		new_element->x = heap_element->x;
		heapC.insert(new_element);
	}
	for (int i = 0; i < heapB.size; i++) {
		AAA* heap_element = (AAA*)(heapB.storage[i]);
		AAA* new_element = new AAA;
		new_element->x = heap_element->x;
		heapC.insert(new_element);
	}

	return heapC;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap heapA = heap::create(MAX_SIZE, cmpAAA);
	heap::Heap heapB = heap::create(MAX_SIZE, cmpAAA);
	for (;;)
	{
		cout << "0 - �����" << endl;
		cout << "1 - [A] ����� �� �����" << endl;
		cout << "2 - [B] ����� �� �����" << endl;
		cout << "3 - [A] �������� ��������" << endl;
		cout << "4 - [B] �������� ��������" << endl;
		cout << "5 - [A] ������� ������������ �������" << endl;
		cout << "6 - [B] ������� ������������ �������" << endl;
		cout << "7 - [A] ������� ����������� �������" << endl;
		cout << "8 - [B] ������� ����������� �������" << endl;
		cout << "9 - ����������� ���" << endl;
		cout << "�������� �����" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  
			exit(0);
		case 1:
			cout << "[A] �����";
			heapA.scan(0);
			break;
		case 2:
			cout << "[B] �����";
			heapB.scan(0);
			break;
		case 3: {
			cout << "[A] ����" << endl;
			while (true) {
				cout << "������� ����" << endl; cin >> k;
				if (k == 0) {
					break;
				}
				AAA* a = new AAA;
				a->x = k;
				heapA.insert(a);
			}
			break;
		}
		case 4: {
			cout << "[B] ����" << endl;
			while (true) {
				cout << "������� ����" << endl; cin >> k;
				if (k == 0) {
					break;
				}
				AAA* a = new AAA;
				a->x = k;
				heapB.insert(a);
			}
			break;
		}
		case 5: {
			cout << "[A] �������� MAX" << endl;
			if (heapA.isEmpty()) {
				cout << "���� �����" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapA.extractMax();
				cout << "���������: " << extracted->x << endl;
			}
			break;
		}
		case 6: {
			cout << "[B] �������� MAX" << endl;
			if (heapB.isEmpty()) {
				cout << "���� �����" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapB.extractMax();
				cout << "���������: " << extracted->x << endl;
			}
			break;
		}
		case 7: {
			cout << "[A] �������� MIN" << endl;
			if (heapA.isEmpty()) {
				cout << "���� �����" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapA.extractMin();
				cout << "���������: " << extracted->x << endl;
			}
			break;
		}
		case 8: {
			cout << "[B] �������� MIN" << endl;
			if (heapB.isEmpty()) {
				cout << "���� �����" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapB.extractMin();
				cout << "���������: " << extracted->x << endl;
			}
			break;
		}
		case 9: {
			cout << "����������� ���" << endl;
			heap::Heap heapC = unionHeap(heapA, heapB);
			heapC.scan(0);
			heapC.clear();
			break;
		}
		default:  
			cout << endl << "������� �������� �������!" << endl;
		}
	} return 0;
}
