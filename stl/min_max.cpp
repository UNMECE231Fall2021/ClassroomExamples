#include <iostream>

template <typename T>
void min(const T &a, const T &b) {
	return (a < b) ? a : b;
	/*
	 if (a < b) {
	 	return a;
	}
	else {
		return b;
	}
	*/
}

template <typename T>
void max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

int main() {
	int a=1, b=2;
	std::cout << std::min(a, b) << ' ' << std::max(a, b) << '\n';
	return 0;
}
