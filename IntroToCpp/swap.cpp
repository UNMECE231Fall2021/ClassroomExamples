#include <iostream>

void ptr_swap(double *x, double *y) {
	double temp = *x;
	*x = *y;
	*y = temp;
}

void ref_swap(double &x, double &y) {
	double t = x;
	x = y;
	y = t;
}

int main() {
	double a = 9.238549;
	double b = 81.1894;

	std::cout << a << ' ' << b << '\n';
	ptr_swap(&a, &b);
	std::cout << a << ' ' << b << '\n';

	ref_swap(a, b);
	std::cout << a << ' ' << b << '\n';

	return 0;
}
