#include <iostream>
#include <fstream>
using namespace std;


const int INPUT_BUFFER_SIZE = 10;
const char* DB_FILENAME = "data.bin";


struct ListNode {
	int value;
	ListNode* next;
};


bool isEmpty(ListNode* head) {
	return head == nullptr;
}


bool append(ListNode*& head, int value) {
	ListNode* newHead = new ListNode;
	if (!newHead) {
		return false;
	}
	newHead->value = value;
	newHead->next = head;
	head = newHead;
	return true;
}


bool del(ListNode*& head, int value) {
	ListNode* previous, * current, * temp;
	if (head->value == value) {
		temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	previous = head;
	current = head->next;
	while (current != nullptr && current->value != value) {
		previous = current;
		current = current->next;
	}
	if (current != nullptr) {
		temp = current;
		previous->next = current->next;
		delete temp;
		return true;
	}
	return false;
}


int find(ListNode* head, int value) {
	int index = 0;
	while (head != nullptr && head->value != value) {
		head = head->next;
		index++;
	}
	if (head != nullptr) {
		return index;
	}
	return -1;
}


void clear(ListNode*& head) {
	ListNode* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}


void inputData(ListNode*& head) {
	char input[INPUT_BUFFER_SIZE];
	while (true) {
		cout << "Введите значение для добавления (- для выхода): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "Выход..." << endl;
			break;
		}
		int value = atoi(input);
		if (append(head, value)) {
			cout << "Значение добавлено" << endl;
		}
		else {
			cout << "Не удалось добавить значение" << endl;
		}
	}
}


void deleteData(ListNode*& head) {
	if (isEmpty(head)) {
		cout << "Список пуст" << endl;
		return;
	}
	char input[INPUT_BUFFER_SIZE];
	while (true) {
		cout << "Введите значение для удаления (- для выхода): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "Выход..." << endl;
			break;
		}
		int value = atoi(input);
		if (del(head, value)) {
			cout << "Значение удалено" << endl;
		}
		else {
			cout << "Не удалось удалить значение" << endl;
		}
	}
}


void searchData(ListNode* head) {
	if (isEmpty(head)) {
		cout << "Список пуст" << endl;
		return;
	}
	char input[INPUT_BUFFER_SIZE];
	while (true) {
		cout << "Введите значение для поиска (- для выхода): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "Выход..." << endl;
			break;
		}
		int value = atoi(input);
		int found_index = find(head, value);
		if (found_index != -1) {
			cout << "Индекс найденного элемента: " << found_index << endl;
		}
		else {
			cout << "Не удалось найти элемент с таким значением" << endl;
		}
	}
}


void outputData(ListNode* head) {
	if (isEmpty(head)) {
		cout << "Список пуст" << endl;
		return;
	}
	cout << "{ ";
	while (head != nullptr) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << "}" << endl;
}


void sumData(ListNode* head) {
	int sum = 0;
	while (head != nullptr) {
		if ((head->value < 0) && !(head->value & 1)) {
			sum += head->value;
		}
		head = head->next;
	}
	if (sum == 0) {
		cout << "В списке нет отрицательных элементов кратных двум" << endl;
	}
	else {
		cout << "Сумма отрицательных элементов кратных двум: " << sum << endl;
	}
}


void loadData(ListNode*& head) {
	ifstream fin(DB_FILENAME, ios::binary);
	if (!fin) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	clear(head);
	int value;
	fin.read((char*)&value, sizeof(int));
	while (!fin.eof()) {
		append(head, value);
		fin.read((char*)&value, sizeof(int));
	}
	fin.close();
	cout << "Данные загружены из файла" << endl;
}


void saveData(ListNode* head) {
	ofstream fout(DB_FILENAME, ios::binary);
	if (!fout) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	while (head != nullptr) {
		fout.write((char*)&head->value, sizeof(head->value));
		head = head->next;
	}
	fout.close();
	cout << "Данные сохранены в файл" << endl;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	ListNode* head = nullptr;

	while (true) {
		int opcode;
		cout << "-------------------------" << endl;
		cout << "Введите номер действия:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Добавление элемента в список" << endl
			<< "[2] Удаление элемента списка" << endl
			<< "[3] Поиск элемента в списке" << endl
			<< "[4] Вывод списка" << endl
			<< "[5] Сумма отрицательных элементов кратных двум" << endl
			<< "[6] Загрузка из файла" << endl
			<< "[7] Сохранение в файл" << endl
			<< "[8] Очистка списка" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			cout << "Выход из программы..." << endl;
			exit(0);
		case 1:
			inputData(head);
			break;
		case 2:
			deleteData(head);
			break;
		case 3:
			searchData(head);
			break;
		case 4:
			outputData(head);
			break;
		case 5:
			sumData(head);
			break;
		case 6:
			loadData(head);
			break;
		case 7:
			saveData(head);
			break;
		case 8:
			clear(head);
			cout << "Список очищен" << endl;
			break;
		default:
			cout << "Нет действия с таким номером" << endl;
		}
	}
	clear(head);
}
