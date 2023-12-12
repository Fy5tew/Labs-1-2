#include <iostream>
#include <vector>
#include "funcs.h"
using namespace std;


int get_max(vector<int> vec) {
	int max = 0;
	for (int v : vec) {
		if (v > max) {
			max = v;
		}
	}
	return max;
}


void max_vector_el() {
	vector<int> vec = { 4, 7, 2, 2, 4, 7, 9, 1, 4, 6 };
	int max = get_max(vec);
	cout << "�������� �������: "; print(vec); cout << endl;
	cout << "������������ ������� �������: " << max << endl;
}
