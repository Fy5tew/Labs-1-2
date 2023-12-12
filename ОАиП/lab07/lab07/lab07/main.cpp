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
			cout << "Введенные данные не являются числом" << endl;
		}
		catch (const out_of_range&) {
			cout << "Введенное значение слишком большое" << endl;
		}
	}
}


void inputData(Stack<int>& stack) {
	int input_count = inputInteger("Введите количество элементов для ввода: ");
	for (int i = 0; i < input_count; i++) {
		int value = inputInteger(">>> ");
		try {
			stack.push(value);
			cout << "Елемент добавлен" << endl;
		}
		catch (const bad_alloc&) {
			cout << "Не удалось добавить элемент" << endl;
		}
	}
}


void outputData(Stack<int>& stack) {
	cout << "Элементы стека: " << stack.toString() << endl;
}


void deleteData(Stack<int>& stack) {
	cout << "Enter для удаления элементов (- для выхода)" << endl;
	while (true) {
		string input = inputString(">>> ");
		if (input == "-") {
			cout << "Выход..." << endl;
			break;
		}
		try {
			int value = stack.pop();
			cout << "Удаленный элемент: " << value << endl;
		}
		catch (const out_of_range&) {
			cout << "Стек пуст" << endl;
			break;
		}
	}
}


void clearData(Stack<int>& stack) {
	stack.clear();
	cout << "Стек очищен" << endl;
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
	cout << "Исходный стек: " << stack.toString() << endl
		<< "Стек элементов больших 50: " << stack1.toString() << endl
		<< "Стек остальных элементов: " << stack2.toString() << endl;
	stack1.clear();
	stack2.clear();
}


void loadData(Stack<int>& stack) {
	string filename = inputString("Укажите файл для загрузки данных: ");
	try {
		readStackFromFile(stack, filename);
		cout << "Данные загружены из файла " << filename << endl;
	}
	catch (const domain_error& err) {
		cout << "Не удалось загрузить данные: " << err.what() << endl;
	}
}


void saveData(Stack<int>& stack) {
	string filename = inputString("Укажите файл для сохранения данных: ");
	try {
		writeStackToFile(stack, filename);
		cout << "Данные сохранены в файл " << filename << endl;
	}
	catch (const domain_error& err) {
		cout << "Не удалось сохранить данные: " << err.what() << endl;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack<int> stack;

	while (true) {
		cout << "Выберите действие:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Добавление данных в стек" << endl
			<< "[2] Вывод стека" << endl
			<< "[3] Удаление данных из стека" << endl
			<< "[4] Очистка стека" << endl
			<< "[5] Разделение стека" << endl
			<< "[6] Загрузка стека из файла" << endl
			<< "[7] Сохрание стека в файл" << endl
			<< "";
		int opcode = inputInteger(">>> ");
		switch (opcode) {
		case 0:
			cout << "Выход..." << endl;
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
			cout << "Неверная опция" << endl;
		}
		system("pause");
		system("cls");
	}
}
