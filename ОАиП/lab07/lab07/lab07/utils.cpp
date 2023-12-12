#include <fstream>
#include <string>
#include "Stack.h"
using namespace std;



void writeStackToFile(Stack<int>& stack, string filename) {
	std::ofstream fout(filename, ios_base::binary);
	if (!fout) {
		throw std::domain_error("can't open file");
	}
	Stack<int> reversed_stack;
	while (!stack.isEmpty()) {
		reversed_stack.push(stack.pop());
	}
	while (!reversed_stack.isEmpty()) {
		int value = reversed_stack.pop();
		stack.push(value);
		fout.write((char*)&value, sizeof(value));
	}
	fout.close();
}


void readStackFromFile(Stack<int>& stack, string filename) {
	std::ifstream fin(filename, ios::binary);
	if (!fin) {
		throw std::domain_error("can't open file");
	}
	stack.clear();
	int buffer;
	fin.read((char*)&buffer, sizeof(buffer));
	while (!fin.eof()) {
		stack.push(buffer);
		fin.read((char*)&buffer, sizeof(buffer));
	}
	fin.close();
}
