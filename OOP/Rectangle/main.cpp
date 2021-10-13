#include <iostream>
#include "rectangle.hpp"
#include "cube.hpp"

int main() {
	Rectangle r(9, 12);
	Cube a;
	Cube b(1, 2, 3);

	std::cout << a << '\n';
	std::cout << b << '\n';

	a.set_length(3);
	a.set_width(4);
	a.set_depth(2);

	Cube c(a);
	std::cout << a << '\n';
	std::cout << c << '\n';

	return 0;
}
