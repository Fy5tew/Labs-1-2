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
	cout << "ФИО: " << student.lastName << " " << student.firstName << " " << student.surname << endl
		<< "Класс: " << student.grade << endl
		<< "Средний балл: " << student.averangeMark << endl
		<< "\tПредмет | Оценка" << endl;
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		cout << student.subjects[i] << " " << student.marks[i] << endl;
	}
}


void displayStudents(vector<Student>& students) {
	for (int i = 0; i < students.size(); i++) {
		cout << CHAPTER_SEP << "Ученик#" << i + 1 << CHAPTER_SEP << endl;
		cout << "ID: " << i << endl;
		displayStudent(students[i]);
	}
}


Student inputStudent() {
	Student student;

	cout << "Фамилия: "; cin >> student.lastName;
	cout << "Имя: "; cin >> student.firstName;
	cout << "Отчество: "; cin >> student.surname;
	cout << "Класс: "; cin >> student.grade;
	cout << "\tПредметы (всего " << SUBJECTS_COUNT << "):" << endl;
	float avg = 0;
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		cout << "Название: "; cin >> student.subjects[i];
		cout << "Оценка: "; cin >> student.marks[i];
		avg += student.marks[i];
	}
	student.averangeMark = avg / SUBJECTS_COUNT;

	return student;
}


void inputStudents(int count, vector<Student>& students) {
	for (int i = 0; i < count; i++) {
		cout << CHAPTER_SEP << "Ученик#" << i + 1 << CHAPTER_SEP << endl;
		students.push_back(inputStudent());
	}
}


void inputOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[ВВОД ДАННЫХ]" << BLOCK_SEP << endl;
	int count;
	cout << "Введите количество учеников для ввода: "; cin >> count;
	inputStudents(count, students);
}


void outputOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[ВЫВОД ДАННЫХ]" << BLOCK_SEP << endl;
	displayStudents(students);
}


void findOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[ПОИСК ПО ФАМИЛИИ]" << BLOCK_SEP << endl;
	while (true) {
		char last_name[STRING_SIZE]; 
		int student_id = -1;
		cout << "Введите фамилию для поиска ('-' для выхода): "; cin >> last_name;
		if (strcmp("-", last_name) == 0) {
			cout << "Выход..." << endl;
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
			cout << "Не найдено записей с фамилией '" << last_name << "'" << endl;
		}
		cout << CHAPTER_SEP << endl;
	}
}


void deleteOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[УДАЛЕНИЕ ДАННЫХ]" << BLOCK_SEP << endl;
	cout << "Введите ID студента для удаления или -1 для выхода" << endl;
	int delete_id;
	int last_deleted_id = students.size();
	while (true) {
		if (students.size() == 0) {
			cout << "Не осталось записей для удаления" << endl;
			break;
		}
		cout << ">>> "; cin >> delete_id;
		if (delete_id == -1) {
			cout << "Выход..." << endl;
			break;
		}
		if (delete_id >= students.size()) {
			cout << "Нет ученика с таким ID" << endl;
			continue;
		}
		if (last_deleted_id <= delete_id) {
			cout << "До этого были удалены данные с меньшими ID. "
				<< "Дальнейшее удаление может быть непредсказуемым. "
				<< "Рекомендуется заново просмотреть ID записей. "
				<< endl;
			break;
		}
		students.erase(students.begin() + delete_id);
		cout << "Удалена запись #" << delete_id << endl;
		last_deleted_id = delete_id;
	}
}


void loadOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[ЗАГРУЗКА ДАННЫХ]" << BLOCK_SEP << endl;
	char is_load;
	cout << "Загрузка данных из хранилица перезапишет все существующие данные. Продолжить? [y/n]: ";
	cin >> is_load;
	if (is_load != 'y') {
		cout << "Загрузка отменена" << endl;
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
	cout << "Загружено " << students.size() << " записей" << endl;
}


void saveOption(vector<Student>& students) {
	cout << BLOCK_SEP << "[СОХРАНЕНИЕ ДАННЫХ]" << BLOCK_SEP << endl;
	ofstream file;
	file.open(DB_FILENAME, ios::binary);
	for (Student& student : students) {
		file.write((char*)&student, sizeof(Student));
	}
	file.close();
	cout << "Данные успешно сохранены" << endl;
}


void exitOption() {
	cout << "Завершение программы..." << endl;
	exit(0);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int opcode;
	vector<Student> students;
	
	while (true) {
		cout << BLOCK_SEP << "[МЕНЮ]" << BLOCK_SEP << endl;
		cout << "Выберите опцию:" << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Ввод данных" << endl
			<< "[2] Вывод данных" << endl
			<< "[3] Поиск по фамилии" << endl
			<< "[4] Удаление данных" << endl
			<< "[5] Загрузка данных из файла" << endl
			<< "[6] Сохрание данных в файл" << endl
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
			cout << "Неизвестная опция." << endl;
			break;
		}
	}
}
