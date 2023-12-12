#include <Windows.h>
#include <iostream>
#include "List.h"
using namespace std;


const int STRING_SIZE = 25;


struct Student {
	char last_name[STRING_SIZE];
	char first_name[STRING_SIZE];
	char surname[STRING_SIZE];
	char grade[STRING_SIZE];
	float averange_mark;
};


void print(void* data) {
	Student* student = (Student*)data;
	cout << student->last_name << " "
		<< student->first_name << " "
		<< student->surname << " "
		<< "(" << student->grade << ")"
		<< " - " << student->averange_mark
		<< endl;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student s1 = { "����������", "������", "�������������", "11�", 9.3 };
	Student s2 = { "��������", "�������", "����������", "11�", 9.9 };
	Student s3 = { "�����", "�������", "�������", "11�", 8.5 };

	Object list = Create();

	while (true) {
		int opcode;
		cout << "------------------------------" << endl;
		cout << "�������� ��������:" << endl
			<< "[0] �����" << endl
			<< "[1] ������� ��������� � ������" << endl
			<< "[2] ����� ������" << endl
			<< "[3] ����� ���������" << endl
			<< "[4] ���������� ��������� � ������" << endl
			<< "[5] ������� ������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0: {
			cout << "�����..." << endl;
			exit(0);
		}
		case 1: {
			list.Insert(&s2);
			list.Insert(&s3);
			list.InsertEnd(&s1);
			cout << "�������� ���������" << endl;
			break;
		}
		case 2: {
			cout << "�������� ������:" << endl;
			list.PrintList(print);
			break;
		}
		case 3: {
			Element* el = list.Search(&s1);
			cout << "�������: ";
			print(el->Data);
			break;
		}
		case 4: {
			cout << "���������� ��������� � ������: " << list.CountList() << endl;
			break;
		}
		case 5: {
			if (list.DeleteList()) {
				cout << "������ ������" << endl;
			}
			else {
				cout << "���-�� ����� �� ���..." << endl;
			}
			break;
		}
		default:
			cout << "��� �������� � ����� �������" << endl;
		}
	}
	list.DeleteList();
}
