#include <random>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;


const int ARRAY_SIZE = 50;
const int MIN_VALUE = 0;
const int MAX_VALUE = 100;


int getRandomNumber(int min, int max) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);

	return uni(rng);
}


vector<int> generateArray(int size, int min, int max) {
	vector<int> arr = vector<int>(size);
	for (int i = 0; i < size; i++) {
		arr[i] = getRandomNumber(min, max);
	}
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


int partition(vector<int>& array, int low, int high) {
	int pivot = array[low]; // ������� �������
	int i = low + 1; // ������ ��� ������� �� ��������� ����� �� �������� ��������
	int j = high; // ������ ��� ������� �� ��������� ������ �� �������� ��������
	while (true) {
		// ������� ������� �����, ������� ������ �������� ��������
		while (i <= j && array[i] <= pivot) {
			i++;
		}
		// ������� ������� ������, ������� ������ �������� ��������
		while (j >= i && array[j] >= pivot) {
			j--;
		}
		if (i >= j) {
			// ����� �������� �������� �������
			break;
		}
		// ���������� ��������
		swap(array[i], array[j]);
	}
	// �������� ������� ������� �� ���� �����
	swap(array[low], array[j]);
	return j; // ���������� ������� �������� ��������
}


void quickSort(vector<int>& array, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(array, low, high);
		// ���������� ��������� �������� ����� � ������ �� �������� ��������
		quickSort(array, low, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, high);
	}
}


vector<int> quickSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);

	int low = 0;
	int high = sorted_array.size() - 1;

	quickSort(sorted_array, low, high);

	return sorted_array;
}


void heapify(vector<int>& array, size_t size, size_t rootIndex) {
	size_t largest = rootIndex; // ������ ����������� �������� (������ ����)
	size_t leftChild = 2 * rootIndex + 1; // ������ ������ �������
	size_t rightChild = 2 * rootIndex + 2; // ������ ������� �������

	// ���� ����� �������� ������� ������ �����
	if (leftChild < size && array[leftChild] > array[largest]) {
		largest = leftChild;
	}

	// ���� ������ �������� ������� ������ �����
	if (rightChild < size && array[rightChild] > array[largest]) {
		largest = rightChild;
	}

	if (largest != rootIndex) {
		swap(array[rootIndex], array[largest]);

		// ���������� ��������� heapify � ���������
		heapify(array, size, largest);
	}
}


vector<int> heapSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);

	size_t size = sorted_array.size();

	// ���������� max-���� (���������� ��������)
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(sorted_array, size, i);
	}

	// ���� �� ������ ��������� �������� �� ����
	for (int i = size - 1; i >= 0; i--) {
		swap(sorted_array[0], sorted_array[i]);

		// ��������� heapify � ����������� ����
		heapify(sorted_array, i, 0);
	}

	return sorted_array;
}


void merge(vector<int>& array, int left, int mid, int right) {
	int leftSize = mid - left + 1; // ������ ������ ����������
	int rightSize = right - mid; // ������ ������� ����������
	// ������� ��������� ������� ��� �������� ������ � ������� �����������
	vector<int> leftArray(leftSize);
	vector<int> rightArray(rightSize);
	// �������� ������ �� ��������� �������
	for (int i = 0; i < leftSize; ++i) {
		leftArray[i] = array[left + i];
	}
	for (int j = 0; j < rightSize; ++j) {
		rightArray[j] = array[mid + 1 + j];
	}
	// ������� ��������� �������� � �������� ������
	int i = 0; // ������ ��� ������ ����������
	int j = 0; // ������ ��� ������� ����������
	int k = left; // ������ ��� ��������� �������
	while (i < leftSize && j < rightSize) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			++i;
		}
		else {
			array[k] = rightArray[j];
			++j;
		}
		++k;
	}
	// ����������� ���������� ��������� ������ ����������
	while (i < leftSize) {
		array[k] = leftArray[i];
		++i;
		++k;
	}
	// ����������� ���������� ��������� ������� ����������
	while (j < rightSize) {
		array[k] = rightArray[j];
		++j;
		++k;
	}
}


void mergeSort(vector<int>& array, int left, int right) {
	
	if (left < right) {
		int mid = left + (right - left) / 2;

		// ���������� ��������� ����� � ������ �������� �������
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		// ������� ���� ��������������� �������
		merge(array, left, mid, right);
	}
}


vector<int> mergeSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);
	mergeSort(sorted_array, 0, sorted_array.size() - 1);
	return sorted_array;
}


float testSort(vector<int>(*sortFunc)(vector<int>), vector<int> array) {
	clock_t time_req;
	time_req = clock();
	sortFunc(array);
	time_req = clock() - time_req;
	return (float)time_req/CLOCKS_PER_SEC;
}


void testSortMethods(int array_size) {
	vector<int> array = generateArray(array_size, MIN_VALUE, MAX_VALUE);
	cout << "������ ������� " << array_size << endl;
	cout << "������� ����������: " << testSort(quickSort, array) << "s" << endl;
	cout << "������������� ����������: " << testSort(heapSort, array) << "s" << endl;
	cout << "���������� ��������: " << testSort(mergeSort, array) << "s" << endl;
	cout << endl;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	vector<int> arr = generateArray(ARRAY_SIZE, MIN_VALUE, MAX_VALUE);
	vector<int> hoare_sorted_arr = quickSort(arr);
	vector<int> heap_sorted_arr = heapSort(arr);
	vector<int> merge_sorted_arr = mergeSort(arr);

	printArray(arr, "�������� ������: ");
	printArray(hoare_sorted_arr, "������� ����������: ");
	printArray(heap_sorted_arr, "������������� ����������: ");
	printArray(merge_sorted_arr, "���������� ��������: ");

	for (int i = 1; i <= 10; i++) {
		testSortMethods(i * 10000);
	}
}
