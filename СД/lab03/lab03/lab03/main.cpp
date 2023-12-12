#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int STRING_SIZE = 255;
const char SEPARATOR = '=';
string FILENAME = "";


enum class InputMode {
	USE_CACHED,
	REWRITE_CACHED,
};


string inputFilename(InputMode input_mode = InputMode::USE_CACHED) {
	if (input_mode == InputMode::REWRITE_CACHED || FILENAME.empty()) {
		cout << "Введите название файла: "; cin >> FILENAME;
	}
	return FILENAME;
}


void separateSection(string section_title) {
	cout << setw(20) << setfill(SEPARATOR) << SEPARATOR
		<< '[' << section_title << ']'
		<< setw(20) << setfill(SEPARATOR) << SEPARATOR
		<< endl;
}


void fileChangeOption() {
	separateSection("ИЗМЕНЕНИЕ ФАЙЛА");
	string filename = inputFilename(InputMode::REWRITE_CACHED);
	cout << "Новый выбранный файл: " << filename << endl;
}


void fileInputOption() {
	separateSection("ВВОД ДАННЫХ");
	string filename = inputFilename(InputMode::REWRITE_CACHED);
	ofstream fout(filename, ios_base::out | ios_base::trunc);
	if (fout.fail()) {
		cout << "Не удалось открыть файл '" << filename << "'" << endl;
		return;
	}
	cin.ignore();
	char input_text[STRING_SIZE];
	cout << "Введите строку для записи в файл: "; cin.getline(input_text, STRING_SIZE);
	fout << input_text;
	cout << "Запись в файл завершена." << endl;
	fout.close();
}


void fileOutputOption() {
	separateSection("ВЫВОД ДАННЫХ");
	string filename = inputFilename();
	ifstream fin(filename, ios_base::in);
	if (fin.fail()) {
		cout << "Не удалось открыть файл '" << filename << "'" << endl;
		return;
	}
	char output_text[STRING_SIZE];
	fin.getline(output_text, STRING_SIZE);
	cout << output_text << endl;
	fin.close();
}


void fileClearOption() {
	separateSection("ОЧИСТКА ФАЙЛА");
	string filename = inputFilename();
	ofstream f(filename, ios_base::trunc);
	if (f.fail()) {
		cout << "Не удалось открыть файл '" << filename << "'" << endl;
		return;
	}
	cout << "Содержимое файла очищено" << endl;
	f.close();
}


void fileDeleteOption() {
	separateSection("УДАЛЕНИЕ ФАЙЛА");
	string filename = inputFilename();
	remove(filename.c_str());
	cout << "Файл удален" << endl;
	FILENAME = "";
}


void exitProgramOption() {
	separateSection("ВЫХОД ИЗ ПРОГРАММЫ");
	string filename = inputFilename();
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		separateSection("МЕНЮ");
		int opcode;
		cout << "[Выбранный файл: " << (FILENAME.empty() ? "Отсутствует" : FILENAME) << "]" << endl;
		cout << "Выберите необходимую операцию: " << endl
			<< "[0] Выход из программы" << endl
			<< "[1] Запись данных в файл" << endl
			<< "[2] Чтение файла" << endl
			<< "[3] Удаление содержимого в файла" << endl
			<< "[4] Удаление файла" << endl
			<< "[5] Изменение выбранного файла" << endl
			<< ">>> "; cin >> opcode;
		switch (opcode) {
		case 0:
			exitProgramOption();
			break;
		case 1:
			fileInputOption();
			break;
		case 2:
			fileOutputOption();
			break;
		case 3:
			fileClearOption();
			break;
		case 4:
			fileDeleteOption();
			break;
		case 5:
			fileChangeOption();
			break;
		default:
			cout << "Неверный номер операции" << endl;
			break;
		}
	}
}
