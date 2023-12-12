#include <Windows.h>
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


string inputString(string placeholder = "") {
	cout << placeholder;
	string input_string;
	getline(cin, input_string);
	return input_string;
}


int inputInteger(string placeholder = "") {
	while (true) {
		try {
			string string_input = inputString(placeholder);
			int integer_input = stoi(string_input);
			return integer_input;
		}
		catch (const out_of_range&) {
			cout << "Введенное число слишком большое" << endl;
		}
		catch (const invalid_argument&) {
			cout << "Введенные данные не являются числом" << endl;
		}
	}
}


int inputUnsignedInteger(string placeholder = "") {
	while (true) {
		int integer_input = inputInteger(placeholder);
		if (integer_input >= 0) {
			return integer_input;
		}
		cout << "Введенное число не является целым" << endl;
	}
}


void inputData(Queue<int>* queue) {
	int input_count = inputInteger("Введите количество элементов для ввода: ");
	for (int i = 0; i < input_count; i++) {
		try {
			int value = inputInteger(">>> ");
			queue->push(value);
			cout << "Элемент добавлен" << endl;
		}
		catch (const out_of_range&) {
			cout << "Очередь заполнена" << endl;
			break;
		}
	}
}


void deleteData(Queue<int>* queue) {
	cout << "Enter для удаления (- для выхода):" << endl;
	while (true) {
		string input_string = inputString(">>> ");
		if (input_string == "-") {
			cout << "Выход..." << endl;
			break;
		}
		try {
			cout << queue->pop() << endl;
		}
		catch (const out_of_range&) {
			cout << "Очередь пуста" << endl;
			break;
		}
	}
}


void outputData(Queue<int>* queue) {
	cout << queue->toString() << endl
		<< "Количество элементов: " << queue->getSize() << "/" << queue->getMaxSize() << endl;
}


void clearData(Queue<int>* queue) {
	queue->clear();
	cout << "Данные очищены" << endl;
}


void splitQueue(Queue<int>* queue) {
	Queue<int>* queue1 = new Queue<int>(queue->getMaxSize());
	Queue<int>* queue2 = new Queue<int>(queue->getMaxSize());
	int size = queue->getSize();
	for (int i = 0; i < size; i++) {
		int value = queue->pop();
		queue->push(value);
		if ((value & 1) != 0) {
			queue1->push(value);
		}
		else {
			queue2->push(value);
		}
	}
	cout << "Исходная очередь: " << queue->toString() << endl
		<< "Очередь четных элементов: " << queue1->toString() << endl
		<< "Очередь нечетных элементов: " << queue2->toString() << endl;

	queue1->clear();
	queue2->clear();
	delete queue1;
	delete queue2;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max_queue_size = inputUnsignedInteger("Укажите максимальный размер очереди: ");
	cout << "Максимальный размер очереди: " << max_queue_size << endl;
	system("pause");
	system("cls");

	Queue<int>* queue = new Queue<int>(max_queue_size);

	while (true) {
		cout << "Выберите опцию:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Ввод данных" << endl
			<< "[2] Удаление данных" << endl
			<< "[3] Вывод данных" << endl
			<< "[4] Очистка данных" << endl
			<< "[5] Разделение очереди" << endl;
		int opcode = inputInteger(">>> ");
		switch (opcode) {
		case 0:
			cout << "Выход..." << endl;
			queue->clear();
			delete queue;
			exit(0);
		case 1:
			inputData(queue);
			break;
		case 2:
			deleteData(queue);
			break;
		case 3:
			outputData(queue);
			break;
		case 4:
			clearData(queue);
			break;
		case 5:
			splitQueue(queue);
			break;
		default:
			cout << "Нет опции с таким номером" << endl;
		}
		system("pause");
		system("cls");
	}
}
