#include <Windows.h>
#include <iostream>
#include <string>
#include "Stack.h"
#include "utils.h"
using namespace std;


string inputString(string placeholder = "") {
	cout << placeholder;
	string input_string;
	getline(cin, input_string);
	return input_string;
}


int inputInteger(string placeholder = "") {
	while (true) {
		string input_string = inputString(placeholder);
		try {
			int input_integer = stoi(input_string);
			return input_integer;
		}
		catch (const invalid_argument&) {
			cout << "��������� ������ �� �������� ������" << endl;
		}
		catch (const out_of_range&) {
			cout << "��������� �������� ������� �������" << endl;
		}
	}
}


void inputData(Stack<int>& stack) {
	int input_count = inputInteger("������� ���������� ��������� ��� �����: ");
	for (int i = 0; i < input_count; i++) {
		int value = inputInteger(">>> ");
		try {
			stack.push(value);
			cout << "������� ��������" << endl;
		}
		catch (const bad_alloc&) {
			cout << "�� ������� �������� �������" << endl;
		}
	}
}


void outputData(Stack<int>& stack) {
	cout << "�������� �����: " << stack.toString() << endl;
}


void deleteData(Stack<int>& stack) {
	cout << "Enter ��� �������� ��������� (- ��� ������)" << endl;
	while (true) {
		string input = inputString(">>> ");
		if (input == "-") {
			cout << "�����..." << endl;
			break;
		}
		try {
			int value = stack.pop();
			cout << "��������� �������: " << value << endl;
		}
		catch (const out_of_range&) {
			cout << "���� ����" << endl;
			break;
		}
	}
}


void clearData(Stack<int>& stack) {
	stack.clear();
	cout << "���� ������" << endl;
}


void splitData(Stack<int>& stack) {
	Stack<int> reversed_stack;
	while (!stack.isEmpty()) {
		reversed_stack.push(stack.pop());
	}
	Stack<int> stack1, stack2;
	while (!reversed_stack.isEmpty()) {
		int value = reversed_stack.pop();
		stack.push(value);
		if (value > 50) {
			stack1.push(value);
		}
		else {
			stack2.push(value);
		}
	}
	cout << "�������� ����: " << stack.toString() << endl
		<< "���� ��������� ������� 50: " << stack1.toString() << endl
		<< "���� ��������� ���������: " << stack2.toString() << endl;
	stack1.clear();
	stack2.clear();
}


void loadData(Stack<int>& stack) {
	string filename = inputString("������� ���� ��� �������� ������: ");
	try {
		readStackFromFile(stack, filename);
		cout << "������ ��������� �� ����� " << filename << endl;
	}
	catch (const domain_error& err) {
		cout << "�� ������� ��������� ������: " << err.what() << endl;
	}
}


void saveData(Stack<int>& stack) {
	string filename = inputString("������� ���� ��� ���������� ������: ");
	try {
		writeStackToFile(stack, filename);
		cout << "������ ��������� � ���� " << filename << endl;
	}
	catch (const domain_error& err) {
		cout << "�� ������� ��������� ������: " << err.what() << endl;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack<int> stack;

	while (true) {
		cout << "�������� ��������:" << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ���������� ������ � ����" << endl
			<< "[2] ����� �����" << endl
			<< "[3] �������� ������ �� �����" << endl
			<< "[4] ������� �����" << endl
			<< "[5] ���������� �����" << endl
			<< "[6] �������� ����� �� �����" << endl
			<< "[7] �������� ����� � ����" << endl
			<< "";
		int opcode = inputInteger(">>> ");
		switch (opcode) {
		case 0:
			cout << "�����..." << endl;
			exit(0);
		case 1:
			inputData(stack);
			break;
		case 2:
			outputData(stack);
			break;
		case 3:
			deleteData(stack);
			break;
		case 4:
			clearData(stack);
			break;
		case 5:
			splitData(stack);
			break;
		case 6:
			loadData(stack);
			break;
		case 7:
			saveData(stack);
			break;
		default:
			cout << "�������� �����" << endl;
		}
		system("pause");
		system("cls");
	}
}
