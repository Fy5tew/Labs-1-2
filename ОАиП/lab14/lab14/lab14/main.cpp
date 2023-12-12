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
	int pivot = array[low]; // Опорный элемент
	int i = low + 1; // Индекс для прохода по элементам слева от опорного элемента
	int j = high; // Индекс для прохода по элементам справа от опорного элемента
	while (true) {
		// Находим элемент слева, который больше опорного элемента
		while (i <= j && array[i] <= pivot) {
			i++;
		}
		// Находим элемент справа, который меньше опорного элемента
		while (j >= i && array[j] >= pivot) {
			j--;
		}
		if (i >= j) {
			// Место опорного элемента найдено
			break;
		}
		// Обмениваем элементы
		swap(array[i], array[j]);
	}
	// Помещаем опорный элемент на свое место
	swap(array[low], array[j]);
	return j; // Возвращаем позицию опорного элемента
}


void quickSort(vector<int>& array, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(array, low, high);
		// Рекурсивно сортируем элементы слева и справа от опорного элемента
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
	size_t largest = rootIndex; // Индекс наибольшего элемента (корень кучи)
	size_t leftChild = 2 * rootIndex + 1; // Индекс левого ребенка
	size_t rightChild = 2 * rootIndex + 2; // Индекс правого ребенка

	// Если левый дочерний элемент больше корня
	if (leftChild < size && array[leftChild] > array[largest]) {
		largest = leftChild;
	}

	// Если правый дочерний элемент больше корня
	if (rightChild < size && array[rightChild] > array[largest]) {
		largest = rightChild;
	}

	if (largest != rootIndex) {
		swap(array[rootIndex], array[largest]);

		// Рекурсивно применяем heapify к поддереву
		heapify(array, size, largest);
	}
}


vector<int> heapSort(vector<int> unsorted_array) {
	vector<int> sorted_array = copyArray(unsorted_array);

	size_t size = sorted_array.size();

	// Построение max-кучи (нисходящая пирамида)
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(sorted_array, size, i);
	}

	// Один за другим извлекаем элементы из кучи
	for (int i = size - 1; i >= 0; i--) {
		swap(sorted_array[0], sorted_array[i]);

		// Применяем heapify к уменьшенной куче
		heapify(sorted_array, i, 0);
	}

	return sorted_array;
}


void merge(vector<int>& array, int left, int mid, int right) {
	int leftSize = mid - left + 1; // Размер левого подмассива
	int rightSize = right - mid; // Размер правого подмассива
	// Создаем временные векторы для хранения левого и правого подмассивов
	vector<int> leftArray(leftSize);
	vector<int> rightArray(rightSize);
	// Копируем данные во временные векторы
	for (int i = 0; i < leftSize; ++i) {
		leftArray[i] = array[left + i];
	}
	for (int j = 0; j < rightSize; ++j) {
		rightArray[j] = array[mid + 1 + j];
	}
	// Слияние временных векторов в исходный вектор
	int i = 0; // Индекс для левого подмассива
	int j = 0; // Индекс для правого подмассива
	int k = left; // Индекс для исходного вектора
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
	// Копирование оставшихся элементов левого подмассива
	while (i < leftSize) {
		array[k] = leftArray[i];
		++i;
		++k;
	}
	// Копирование оставшихся элементов правого подмассива
	while (j < rightSize) {
		array[k] = rightArray[j];
		++j;
		++k;
	}
}


void mergeSort(vector<int>& array, int left, int right) {
	
	if (left < right) {
		int mid = left + (right - left) / 2;

		// Рекурсивно сортируем левую и правую половины массива
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		// Слияние двух отсортированных половин
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
	cout << "Массив размера " << array_size << endl;
	cout << "Быстрая сортировка: " << testSort(quickSort, array) << "s" << endl;
	cout << "Пирамидальная сортировка: " << testSort(heapSort, array) << "s" << endl;
	cout << "Сортировка слиянием: " << testSort(mergeSort, array) << "s" << endl;
	cout << endl;
}


void main() {
	setlocale(LC_CTYPE, "Russian");

	vector<int> arr = generateArray(ARRAY_SIZE, MIN_VALUE, MAX_VALUE);
	vector<int> hoare_sorted_arr = quickSort(arr);
	vector<int> heap_sorted_arr = heapSort(arr);
	vector<int> merge_sorted_arr = mergeSort(arr);

	printArray(arr, "Исходный массив: ");
	printArray(hoare_sorted_arr, "Быстрая сортировка: ");
	printArray(heap_sorted_arr, "Пирамидальная сортировка: ");
	printArray(merge_sorted_arr, "Сортировка слиянием: ");

	for (int i = 1; i <= 10; i++) {
		testSortMethods(i * 10000);
	}
}
