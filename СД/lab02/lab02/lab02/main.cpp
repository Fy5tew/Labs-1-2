#include <Windows.h>
#include <iostream>

#include "formatting.h"
#include "options.h"
#include "database.h"

using namespace std;


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Database database;

	while (true) {
		int opcode;
		cout << separateSection("����") << endl
			<< "�������� ��������:" << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ���� ������" << endl
			<< "[2] ����� ������" << endl
			<< "[3] ����� ������" << endl
			<< "[4] ���������� ������" << endl
			<< "[5] �������� ������" << endl
			<< "[6] ��������������" << endl
			<< "[7] �������� ������" << endl
			<< "[8] ���������� ������" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			exitProgram();
			break;
		case 1:
			inputData(database);
			break;
		case 2:
			outputData(database);
			break;
		case 3:
			searchData(database);
			break;
		case 4:
			updateData(database);
			break;
		case 5:
			deleteData(database);
			break;
		case 6:
			additionalOptions(database);
			break;
		case 7:
			loadData(database);
			break;
		case 8:
			saveData(database);
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
			break;
		}

		cout << endl;
	}
}
