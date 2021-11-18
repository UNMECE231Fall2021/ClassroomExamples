#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

int main() {
	int a=1, b=2;
	std::cout << a << ' ' << b << '\n';
	std::swap(a, b);
	std::cout << a << ' ' << b << '\n';

	return 0;
}
