#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


const char* MATRIX_A_FILENAME = "A.txt";
const char* MATRIX_B_FILENAME = "B.txt";
const char* MATRIX_C_FILENAME = "C.txt";


vector<vector<int>> inputMatrixA() {
	FILE* file;
	fopen_s(&file, MATRIX_A_FILENAME, "r");

	if (!file) {
		cout << "Не удалось открыть файл " << MATRIX_A_FILENAME << endl;
		exit(1);
	}

	int n;
	fscanf_s(file, "%d", &n);
	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf_s(file, "%d", &matrix[i][j]);
		}
	}

	fclose(file);
	return matrix;
}


vector<int> inputMatrixB() {
	FILE* file;
	fopen_s(&file, MATRIX_B_FILENAME, "r");

	if (!file) {
		cout << "Не удалось открыть файл " << MATRIX_B_FILENAME << endl;
		exit(1);
	}

	int n;
	fscanf_s(file, "%d", &n);
	vector<int> matrix(n);

	for (int i = 0; i < n; i++) {
		fscanf_s(file, "%d", &matrix[i]);
	}

	fclose(file);
	return matrix;
}


vector<int> multiplyMatrix(vector<vector<int>> matrixA, vector<int> matrixB) {
	int n = matrixA.size();
	vector<int> matrixC(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixC[i] += matrixA[i][j] * matrixB[j];
		}
	}

	return matrixC;
}


void outputMatrixC(vector<int> matrixC) {
	FILE* file;
	fopen_s(&file, MATRIX_C_FILENAME, "w");

	if (!file) {
		cout << "Не удалось открыть файл " << MATRIX_C_FILENAME << endl;
		exit(0);
	}

	int n = matrixC.size();

	fprintf(file, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(file, "%d\n", matrixC[i]);
	}

	fclose(file);
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	cout << "Считывание матрицы A..." << endl;
	vector<vector<int>> matrixA = inputMatrixA();

	cout << "Считывание матрицы B..." << endl;
	vector<int> matrixB = inputMatrixB();

	cout << "Перемножение матриц..." << endl;
	vector<int> matrixC = multiplyMatrix(matrixA, matrixB);

	cout << "Сохрание матрицы C..." << endl;
	outputMatrixC(matrixC);

	cout << "Программа завершена" << endl;
}
