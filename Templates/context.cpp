#include <iostream>
#include <string>
#include <vector>
#include <utility>

void swap(int &x,int  &y) {
	int t = x;
	x = y;
	y = t;
}

void swap(float &x,float  &y) {
	float t = x;
	x = y;
	y = t;
}

void swap(std::string &x,std::string  &y) {
	std::string t = x;
	x = y;
	y = t;
}

int main() {
	std::pair<int, float> x = {5, 6.8};
	std::cout << x.first << ' ' << x.second << '\n';
	int a = 11, b = 16;
	float c = 6.25, d = 8.03;
	std::string e("Hey"), f("There");

	std::cout << a << ' ' << b << '\n';
	swap(a, b);
	std::cout << a << ' ' << b << '\n';

	std::cout << c << ' ' << d << '\n';
	swap(c, d);
	std::cout << c << ' ' << d << '\n';

	std::cout << e << ' ' << f << '\n';
	swap(e, f);
	std::cout << e << ' ' << f << '\n';

	return 0;
}
