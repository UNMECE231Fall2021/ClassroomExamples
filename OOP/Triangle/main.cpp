#include <iostream>
#include "triangle.hpp"
#include "shape3D.hpp"
#include "pyramid.hpp"

int main() {
	Triangle t;
	Triangle t2(2, 5);
	Triangle t1000(t2);

	std::cout << t << ", " << t2 << ", " << t1000 << '\n';

	if (t2 == t1000) {
		std::cout << "Triangle t2 and t1000 are equal\n";
	}

	if (t2 != t1000) {
		std::cout << "Triangle t2 and t1000 are not equal\n";
	}

	if (t == t2) {
		std::cout << "t == t2\n";
	}

	if (t != t2) {
		std::cout << "t != t2\n";
	}

	Pyramid p1;
	Pyramid p2(2, 3, 4);
	Pyramid p3(p2);

	if (p2 == p3) {
		std::cout << "Pyramids are equal\n";
	}
	if (p2 != p3) {
		std::cout << "Pyramids are not equal\n";
	}

	p2.set_depth(5);

	if (p2 == p3) {
		std::cout << "Pyramids are equal\n";
	}
	if (p2 != p3) {
		std::cout << "Pyramids are not equal\n";
	}

	std::cout << p1 << '\n';
	std::cout << p2 << '\n';
	std::cout << p3 << '\n';
	
	return 0;
}
