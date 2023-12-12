#include <Windows.h>
#include <iostream>
using namespace std;


double dicho(double (*f)(double), double a, double b, double e) {
	double c = (a + b) / 2;
	if (b - a <= 2 * e) {
		return f(c);
	}
	if (f(a) * f(c) <= 0) {
		return dicho(f, a, c, e);
	}
	else {
		return dicho(f, c, b, e);
	}
}


int F(int m, int n) {
	if (m == 0 || n == 0) {
		return n + 1;
	}
	return F(m - 1, F(m, n - 1));
}


double f(double x) {
	return sin(x);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Задание №1: " << dicho(f, -10, 10, 0.01) << endl;
	cout << "Задание №2: " << F(10, 10) << endl;
}
