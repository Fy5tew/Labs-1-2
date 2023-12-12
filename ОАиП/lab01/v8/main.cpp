#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


const int SUBJECTS_COUNT = 3;
const int STRING_SIZE = 20;

const char* BLOCK_SEP = "====================";
const char* CHAPTER_SEP = "--------------------";

const char* DB_FILENAME = "data.bin";


struct Student {
	char firstName[STRING_SIZE];
	char lastName[STRING_SIZE];
	char surname[STRING_SIZE];
	char grade[STRING_SIZE];
	float averangeMark;
	char subjects[SUBJECTS_COUNT][STRING_SIZE];
	int marks[SUBJECTS_COUNT];
};


void displayStudent(const Student& student) {
	cout << "���: " << student.lastName << " " << student.firstName << " " << student.surname << endl
		<< "�����: " << student.grade << endl
		<< "������� ����: " << student.averangeMark << endl
		<< "\t������� | ������" << endl;
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		cout << student.subjects[i] << " " << student.marks[i] << endl;
	}
}


void displayStudents(vector<Student>& students) {
	for (int i = 0; i < students.size(); i++) {
		cout << CHAPTER_SEP << "������#" << i + 1 << CHAPTER_SEP << endl;
		cout << "ID: " << i << endl;
		displayStudent(students[i]);
	}
}


Student inputStudent() {
	Student student;

	cout << "�������: "; cin >> student.lastName;
	cout << "���: "; cin >> student.firstName;
	cout << "��������: "; cin >> student.surname;
	cout << "�����: "; cin >> student.grade;
	cout << "\t�������� (����� " << SUBJECTS_COUNT << "):" << endl;
	float avg = 0;
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		cout << "��������: "; cin >> student.subjects[i];
		cout << "������: "; cin >> student.marks[i];
		avg += student.marks[i];
	}
	student.averangeMark = avg / SUBJECTS_COUNT;

	return student;
}


void inputStudents(int count, vector<Student>& students) {
	for (int i = 0; i < count; i++) {
		cout << CHAPTER_SEP << "������#" << i + 1 << CHAPTER_SEP << endl;
		students.push_back(inputStudent());
	}
}


void inputOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[���� ������]" << BLOCK_SEP << endl;
	int count;
	cout << "������� ���������� �������� ��� �����: "; cin >> count;
	inputStudents(count, students);
}


void outputOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[����� ������]" << BLOCK_SEP << endl;
	displayStudents(students);
}


void findOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[����� �� �������]" << BLOCK_SEP << endl;
	while (true) {
		char last_name[STRING_SIZE]; 
		int student_id = -1;
		cout << "������� ������� ��� ������ ('-' ��� ������): "; cin >> last_name;
		if (strcmp("-", last_name) == 0) {
			cout << "�����..." << endl;
			break;
		}
		for (int i = 0; i < students.size(); i++) {
			if (strcmp(last_name, students[i].lastName) == 0) {
				student_id = i;
				cout << "ID: " << i << endl;
				displayStudent(students[i]);
			}
		}
		if (student_id == -1) {
			cout << "�� ������� ������� � �������� '" << last_name << "'" << endl;
		}
		cout << CHAPTER_SEP << endl;
	}
}


void deleteOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[�������� ������]" << BLOCK_SEP << endl;
	cout << "������� ID �������� ��� �������� ��� -1 ��� ������" << endl;
	int delete_id;
	int last_deleted_id = students.size();
	while (true) {
		if (students.size() == 0) {
			cout << "�� �������� ������� ��� ��������" << endl;
			break;
		}
		cout << ">>> "; cin >> delete_id;
		if (delete_id == -1) {
			cout << "�����..." << endl;
			break;
		}
		if (delete_id >= students.size()) {
			cout << "��� ������� � ����� ID" << endl;
			continue;
		}
		if (last_deleted_id <= delete_id) {
			cout << "�� ����� ���� ������� ������ � �������� ID. "
				<< "���������� �������� ����� ���� ���������������. "
				<< "������������� ������ ����������� ID �������. "
				<< endl;
			break;
		}
		students.erase(students.begin() + delete_id);
		cout << "������� ������ #" << delete_id << endl;
		last_deleted_id = delete_id;
	}
}


void loadOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[�������� ������]" << BLOCK_SEP << endl;
	char is_load;
	cout << "�������� ������ �� ��������� ����������� ��� ������������ ������. ����������? [y/n]: ";
	cin >> is_load;
	if (is_load != 'y') {
		cout << "�������� ��������" << endl;
		return;
	}
	students.clear();
	Student buf;
	ifstream file;
	file.open(DB_FILENAME, ios::binary);
	file.read((char*)&buf, sizeof(buf));
	while (!file.eof()) {
		students.push_back(buf);
		file.read((char*)&buf, sizeof(buf));
	}
	file.close();
	cout << "��������� " << students.size() << " �������" << endl;
}


void saveOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[���������� ������]" << BLOCK_SEP << endl;
	ofstream file;
	file.open(DB_FILENAME, ios::binary);
	for (Student& student : students) {
		file.write((char*)&student, sizeof(Student));
	}
	file.close();
	cout << "������ ������� ���������" << endl;
}


void exitOption() {
	cout << "���������� ���������..." << endl;
	exit(0);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int opcode;
	vector<Student> students;
	
	while (true) {
		cout << BLOCK_SEP << "[����]" << BLOCK_SEP << endl;
		cout << "�������� �����:" << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ���� ������" << endl
			<< "[2] ����� ������" << endl
			<< "[3] ����� �� �������" << endl
			<< "[4] �������� ������" << endl
			<< "[5] �������� ������ �� �����" << endl
			<< "[6] �������� ������ � ����" << endl
			<< ">>> "; cin >> opcode;

		switch (opcode) {
		case 0:
			exitOption();
			break;
		case 1:
			inputOption(students);
			break;
		case 2:
			outputOption(students);
			break;
		case 3:
			findOption(students);
			break;
		case 4:
			deleteOption(students);
			break;
		case 5:
			loadOption(students);
			break;
		case 6:
			saveOption(students);
			break;
		default:
			cout << "����������� �����." << endl;
			break;
		}
	}
}
