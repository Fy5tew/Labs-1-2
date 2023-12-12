#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


const char* INPUT_FILENAME = "input.txt";
const char* OUTPUT_FILENAME = "output.txt";


vector<int> readData() {
	FILE* file;
	if (fopen_s(&file, INPUT_FILENAME, "r") != 0) {
		cout << "Не удалось открыть файл " << INPUT_FILENAME << endl;
		exit(1);
	}
	vector<int> data;
	while (!feof(file)) {
		int value;
		fscanf_s(file, "%d", &value);
		data.push_back(value);
	}
	fclose(file);
	return data;
}


void writeData(vector<int> data) {
	FILE* file;
	if (fopen_s(&file, OUTPUT_FILENAME, "w") != 0) {
		cout << "Не удалось открыть файл " << INPUT_FILENAME << endl;
		return;
	}
	for (int value : data) {
		char buffer[5];
		_itoa_s(value, buffer, 10);
		strcat_s(buffer, " ");
		fwrite(buffer, strlen(buffer), 1, file);
	}
	fclose(file);
}


vector<int> changePosition(vector<int> data) {
	vector<int> new_data;
	for (int i = 0; i < data.size() / 2; i++) {
		new_data.push_back(data[i]);
		new_data.push_back(data[data.size() - 1 - i]);
	}
	return new_data;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	cout << "Чтение данных..." << endl;
	vector<int> data = readData();

	cout << "Изменение порядка чисел..." << endl;
	vector<int> new_data = changePosition(data);

	cout << "Сохрание данных..." << endl;
	writeData(new_data);

	cout << "Данные сохранены" << endl;
}
