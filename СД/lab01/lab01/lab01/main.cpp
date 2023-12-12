#include <iostream>
#include "tasks.h"
using namespace std;


void main() {
	setlocale(LC_CTYPE, "Russian");
	int opcode;
	while (true) {
		cout << "�������� �������:" << endl
			<< "[0] �����" << endl
			<< "[1] ������ �� (Enum#1)" << endl
			<< "[2] ��� ������ (Enum#4)" << endl
			<< "[3] �������� �������� � ������ ������ (List#6)" << endl
			<< "[4] ����� ������������ ������� ������� (Vector#7)" << endl
			<< "[5] ����������� ������� ���� (Deque#8)" << endl
			<< "[6] ������� ������� �� ������ (List#11)" << endl
			<< "[7] �������� �������� ������ (List#13)" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			cout << "�����..." << endl;
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
			cout << "�������� �����!" << endl;
			break;
		}

		cout << "--------------------" << endl;
	}
}
