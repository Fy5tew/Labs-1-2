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
		cout << "������� �������� ��� ���������� (- ��� ������): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "�����..." << endl;
			break;
		}
		int value = atoi(input);
		if (append(head, value)) {
			cout << "�������� ���������" << endl;
		}
		else {
			cout << "�� ������� �������� ��������" << endl;
		}
	}
}


void deleteData(ListNode*& head) {
	if (isEmpty(head)) {
		cout << "������ ����" << endl;
		return;
	}
	char input[INPUT_BUFFER_SIZE];
	while (true) {
		cout << "������� �������� ��� �������� (- ��� ������): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "�����..." << endl;
			break;
		}
		int value = atoi(input);
		if (del(head, value)) {
			cout << "�������� �������" << endl;
		}
		else {
			cout << "�� ������� ������� ��������" << endl;
		}
	}
}


void searchData(ListNode* head) {
	if (isEmpty(head)) {
		cout << "������ ����" << endl;
		return;
	}
	char input[INPUT_BUFFER_SIZE];
	while (true) {
		cout << "������� �������� ��� ������ (- ��� ������): ";
		cin >> input;
		if (!strcmp(input, "-")) {
			cout << "�����..." << endl;
			break;
		}
		int value = atoi(input);
		int found_index = find(head, value);
		if (found_index != -1) {
			cout << "������ ���������� ��������: " << found_index << endl;
		}
		else {
			cout << "�� ������� ����� ������� � ����� ���������" << endl;
		}
	}
}


void outputData(ListNode* head) {
	if (isEmpty(head)) {
		cout << "������ ����" << endl;
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
		cout << "� ������ ��� ������������� ��������� ������� ����" << endl;
	}
	else {
		cout << "����� ������������� ��������� ������� ����: " << sum << endl;
	}
}


void loadData(ListNode*& head) {
	ifstream fin(DB_FILENAME, ios::binary);
	if (!fin) {
		cout << "�� ������� ������� ����" << endl;
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
	cout << "������ ��������� �� �����" << endl;
}


void saveData(ListNode* head) {
	ofstream fout(DB_FILENAME, ios::binary);
	if (!fout) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	while (head != nullptr) {
		fout.write((char*)&head->value, sizeof(head->value));
		head = head->next;
	}
	fout.close();
	cout << "������ ��������� � ����" << endl;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	ListNode* head = nullptr;

	while (true) {
		int opcode;
		cout << "-------------------------" << endl;
		cout << "������� ����� ��������:" << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ���������� �������� � ������" << endl
			<< "[2] �������� �������� ������" << endl
			<< "[3] ����� �������� � ������" << endl
			<< "[4] ����� ������" << endl
			<< "[5] ����� ������������� ��������� ������� ����" << endl
			<< "[6] �������� �� �����" << endl
			<< "[7] ���������� � ����" << endl
			<< "[8] ������� ������" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			cout << "����� �� ���������..." << endl;
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
			cout << "������ ������" << endl;
			break;
		default:
			cout << "��� �������� � ����� �������" << endl;
		}
	}
	clear(head);
}
