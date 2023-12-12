#include <iostream>
#include "tasks.h"
using namespace std;


void main() {
	setlocale(LC_CTYPE, "Russian");
	int opcode;
	while (true) {
		cout << "Выберите задание:" << endl
			<< "[0] Выход" << endl
			<< "[1] Статус ПК (Enum#1)" << endl
			<< "[2] Дни недели (Enum#4)" << endl
			<< "[3] Добавить элементы в начало списка (List#6)" << endl
			<< "[4] Найти максимальный элемент вектора (Vector#7)" << endl
			<< "[5] Минимальный элемент дэки (Deque#8)" << endl
			<< "[6] Удалить элемент из списка (List#11)" << endl
			<< "[7] Заменить элементы списка (List#13)" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			cout << "Выход..." << endl;
			exit(0);
		case 1:
			set_pc_status();
			break;
		case 2:
			number_to_day();
			break;
		case 3:
			list_append();
			break;
		case 4:
			max_vector_el();
			break;
		case 5:
			min_deque_el();
			break;
		case 6:
			list_delete();
			break;
		case 7:
			forward_list_replace();
			break;
		default:
			cout << "Неверный номер!" << endl;
			break;
		}

		cout << "--------------------" << endl;
	}
}
