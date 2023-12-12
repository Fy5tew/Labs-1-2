#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const char* FILENAME = "data.txt";
const string NUMBER_SYMBOLS = "0123456789";
const char NUMBER_POINT = '.';


void writeInputToFile() {
	string input;
	cout << "Введите строку: ";
	cin >> input;

	ofstream file(FILENAME);
	if (!file) {
		cout << "Не удалось открыть файл" << endl;
		exit(1);
	}
	file << input;
	file.close();
}


string readInputFromFile() {
	ifstream file(FILENAME);
	if (!file) {
		cout << "Не удалось открыть файл" << endl;
		exit(1);
	}
	string input;
	getline(file, input);
	file.close();
	return input;
}


void searchFloatSubstring() {
	string input = readInputFromFile();

	bool found = false;
	string fixed_point_substring = "";
	bool has_point = false;
	char last_symbol = '-';

	for (char c : input) {
		if (NUMBER_SYMBOLS.find(c) != string::npos) {
			fixed_point_substring += c;
			last_symbol = c;
			continue;
		}
		if (last_symbol != '-' && c == NUMBER_POINT && !has_point) {
			fixed_point_substring += c;
			last_symbol = c;
			has_point = true;
			continue;
		}
		if (has_point && last_symbol != NUMBER_POINT) {
			found = true;
			break;
		}
		fixed_point_substring = "";
		has_point = false;
		last_symbol = '-';
	}

	if (found) {
		cout << "Найденное число: " << fixed_point_substring << endl;
	}
	else {
		cout << "Не найдено подстроки с числом" << endl;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	writeInputToFile();
	searchFloatSubstring();
}
