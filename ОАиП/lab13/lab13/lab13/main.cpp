#include <vector>
#include <iostream>
using namespace std;


const int ARRAY_SIZE = 10;


bool isEven(int number) {
	return (number & 1) == 0;
}


bool isOdd(int number) {
	return !isEven(number);
}


vector<int> inputArray(int size, const char* placeholder = "") {
	cout << placeholder << endl;
	cout << "Введите " << size << " элементов" << endl;

	vector<int> arr = vector<int>(size);
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "] ";
		cin >> arr[i];
	}
	cout << endl;

	return arr;
}


void printArray(vector<int> arr, const char* placeholder = "") {
	cout << placeholder;
	cout << "[";
	for (int value : arr) {
		cout << " " << value;
	}
	cout << " ]" << endl << endl;
}


vector<int> copyArray(vector<int> arr) {
	vector<int> new_arr = vector<int>(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		new_arr[i] = arr[i];
	}
	return new_arr;
}


vector<int> mergeEvenOdd(vector<int> even_arr, vector<int> odd_arr) {
	vector<int> even_odd_arr;

	for (int value : even_arr) {
		if (isEven(value)) {
			even_odd_arr.push_back(value);
		}
	}
	for (int value : odd_arr) {
		if (isOdd(value)) {
			even_odd_arr.push_back(value);
		}
	}

	return even_odd_arr;
}


vector<int> selectionSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);

	int k, i, j;
	for (i = 0; i < sorted_array.size() - 1; i++)
	{
		for (j = i + 1, k = i; j < sorted_array.size(); j++) {
			if (sorted_array[j] < sorted_array[k]) {
				k = j;
			}
		}
		int c = sorted_array[k];
		sorted_array[k] = sorted_array[i];
		sorted_array[i] = c;
	}

	return sorted_array;
}


vector<int> shellSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);

	int i, j, step;
	int tmp;
	for (step = sorted_array.size() / 2; step > 0; step /= 2) {
		for (i = step; i < sorted_array.size(); i++) {
			tmp = sorted_array[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < sorted_array[j - step]) {
					sorted_array[j] = sorted_array[j - step];
				}
				else {
					break;
				}
			}
			sorted_array[j] = tmp;
		}
	}

	return sorted_array;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	vector<int> array_a = inputArray(ARRAY_SIZE, "Введите массив A");
	vector<int> array_b = inputArray(ARRAY_SIZE, "Введите массив B");
	vector<int> array_c = mergeEvenOdd(array_a, array_b);
	vector<int> selection_sorted_array_c = selectionSort(array_c);
	vector<int> shell_sorted_array_c = shellSort(array_c);

	printArray(array_a, "Массив A: ");
	printArray(array_b, "Массив B: ");
	printArray(array_c, "Массив C: ");
	printArray(selection_sorted_array_c, "Сортировка выбором: ");
	printArray(shell_sorted_array_c, "Сортировка Шелла: ");
}
