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
		cout << "������� �������� �����: "; cin >> FILENAME;
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
	separateSection("��������� �����");
	string filename = inputFilename(InputMode::REWRITE_CACHED);
	cout << "����� ��������� ����: " << filename << endl;
}


void fileInputOption() {
	separateSection("���� ������");
	string filename = inputFilename(InputMode::REWRITE_CACHED);
	ofstream fout(filename, ios_base::out | ios_base::trunc);
	if (fout.fail()) {
		cout << "�� ������� ������� ���� '" << filename << "'" << endl;
		return;
	}
	cin.ignore();
	char input_text[STRING_SIZE];
	cout << "������� ������ ��� ������ � ����: "; cin.getline(input_text, STRING_SIZE);
	fout << input_text;
	cout << "������ � ���� ���������." << endl;
	fout.close();
}


void fileOutputOption() {
	separateSection("����� ������");
	string filename = inputFilename();
	ifstream fin(filename, ios_base::in);
	if (fin.fail()) {
		cout << "�� ������� ������� ���� '" << filename << "'" << endl;
		return;
	}
	char output_text[STRING_SIZE];
	fin.getline(output_text, STRING_SIZE);
	cout << output_text << endl;
	fin.close();
}


void fileClearOption() {
	separateSection("������� �����");
	string filename = inputFilename();
	ofstream f(filename, ios_base::trunc);
	if (f.fail()) {
		cout << "�� ������� ������� ���� '" << filename << "'" << endl;
		return;
	}
	cout << "���������� ����� �������" << endl;
	f.close();
}


void fileDeleteOption() {
	separateSection("�������� �����");
	string filename = inputFilename();
	remove(filename.c_str());
	cout << "���� ������" << endl;
	FILENAME = "";
}


void exitProgramOption() {
	separateSection("����� �� ���������");
	string filename = inputFilename();
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		separateSection("����");
		int opcode;
		cout << "[��������� ����: " << (FILENAME.empty() ? "�����������" : FILENAME) << "]" << endl;
		cout << "�������� ����������� ��������: " << endl
			<< "[0] ����� �� ���������" << endl
			<< "[1] ������ ������ � ����" << endl
			<< "[2] ������ �����" << endl
			<< "[3] �������� ����������� � �����" << endl
			<< "[4] �������� �����" << endl
			<< "[5] ��������� ���������� �����" << endl
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
			cout << "�������� ����� ��������" << endl;
			break;
		}
	}
}
