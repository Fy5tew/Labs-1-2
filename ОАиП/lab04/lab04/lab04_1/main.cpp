#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


const char* INPUT_FILENAME = "FILE1.txt";
const char* OUTPUT_FILENAME = "FILE2.txt";
const string VOWELS = "����������aeiouy";


bool isVowel(char c) {
	c = tolower(c);
	return VOWELS.find(c) != string::npos;
}


char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	}
	if (c >= '�' && c <= '�') {
		return c + ('�' - '�');
	}
	return c; 
}


int countVowels(string text) {
	int vowel_count = 0;
	for (char c : text) {
		if (isVowel(toLower(c))) {
			vowel_count++;
		}
	}
	return vowel_count;
}


vector<string> readLinesFromFile(string filename) {
	ifstream file(filename);
	if (!file) {
		cout << "�� ������� ������� ���� " << filename << endl;
		exit(0);
	}

	vector<string> lines;
	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}

	file.close();
	return lines;
}


void writeLinesToFile(string filename, const vector<string>& lines) {
	ofstream file(filename);
	if (!file) {
		cout << "�� ������� ������� ���� " << filename << endl;
	}

	for (string line : lines) {
		file << line << std::endl;
	}

	file.close();
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<string> input_lines = readLinesFromFile(INPUT_FILENAME);
	vector<string> output_lines;

	int max_vowels = 0;
	for (string line : input_lines) {
		int vowels = countVowels(line);
		if (vowels > max_vowels) {
			max_vowels = vowels;
		}
	}
	cout << "������������ ���������� ������� ���� � ������: " << max_vowels << endl;

	for (int i = 0; i < input_lines.size(); i++) {
		int vowels = countVowels(input_lines[i]);
		if (vowels >= max_vowels) {
			cout << "����� ������ � ������������ ����������� ������� ����: " << i + 1 << endl;
		}
		else {
			output_lines.push_back(input_lines[i]);
		}
	}

	writeLinesToFile(OUTPUT_FILENAME, output_lines);
}
