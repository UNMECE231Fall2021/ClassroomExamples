#include <iostream>
#include <string>
#include <vector>
#include <utility>

template <typename T1, typename T2>
struct _pair {
	T1 first;
	T2 second;
};

template <typename T>
void print_vector(std::vector<T> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

template <typename X>
X max(X &a, X &b) {
	return (a < b) ? b : a;
}

template <typename Y>
Y min(Y &a, Y &b) {
	return (a > b) ? b : a;
}

/*
template <typename T>
void swap(T &x,T  &y) {
	T t = x;
	x = y;
	y = t;
}
*/

int main() {
	std::pair<int, float> x = {5, 6.8};
	std::cout << x.first << ' ' << x.second << '\n';
	int a = 11, b = 16;
	float c = 6.25, d = 8.03;
	std::string e("Hey"), f("There");

	std::cout << a << ' ' << b << '\n';
	std::swap(a, b);
	std::cout << a << ' ' << b << '\n';

	std::cout << c << ' ' << d << '\n';
	std::swap(c, d);
	std::cout << c << ' ' << d << '\n';

	std::cout << e << ' ' << f << '\n';
	std::swap(e, f);
	std::cout << e << ' ' << f << '\n';

	return 0;
}
