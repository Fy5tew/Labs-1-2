#include "Heap.h"
#include <iostream>
using namespace std;

#define MAX_SIZE 30

heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
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
		cout << "0 - выход" << endl;
		cout << "1 - [A] вывод на экран" << endl;
		cout << "2 - [B] вывод на экран" << endl;
		cout << "3 - [A] добавить элементы" << endl;
		cout << "4 - [B] добавить элементы" << endl;
		cout << "5 - [A] удалить максимальный элемент" << endl;
		cout << "6 - [B] удалить максимальный элемент" << endl;
		cout << "7 - [A] удалить минимальный элемент" << endl;
		cout << "8 - [B] удалить минимальный элемент" << endl;
		cout << "9 - Объединение куч" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  
			exit(0);
		case 1:
			cout << "[A] Вывод";
			heapA.scan(0);
			break;
		case 2:
			cout << "[B] Вывод";
			heapB.scan(0);
			break;
		case 3: {
			cout << "[A] Ввод" << endl;
			while (true) {
				cout << "введите ключ" << endl; cin >> k;
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
			cout << "[B] Ввод" << endl;
			while (true) {
				cout << "введите ключ" << endl; cin >> k;
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
			cout << "[A] Удаление MAX" << endl;
			if (heapA.isEmpty()) {
				cout << "Куча пуста" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapA.extractMax();
				cout << "Извлечено: " << extracted->x << endl;
			}
			break;
		}
		case 6: {
			cout << "[B] Удаление MAX" << endl;
			if (heapB.isEmpty()) {
				cout << "Куча пуста" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapB.extractMax();
				cout << "Извлечено: " << extracted->x << endl;
			}
			break;
		}
		case 7: {
			cout << "[A] Удаление MIN" << endl;
			if (heapA.isEmpty()) {
				cout << "Куча пуста" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapA.extractMin();
				cout << "Извлечено: " << extracted->x << endl;
			}
			break;
		}
		case 8: {
			cout << "[B] Удаление MIN" << endl;
			if (heapB.isEmpty()) {
				cout << "Куча пуста" << endl;
			}
			else {
				AAA* extracted = (AAA*)heapB.extractMin();
				cout << "Извлечено: " << extracted->x << endl;
			}
			break;
		}
		case 9: {
			cout << "Объединение куч" << endl;
			heap::Heap heapC = unionHeap(heapA, heapB);
			heapC.scan(0);
			heapC.clear();
			break;
		}
		default:  
			cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
