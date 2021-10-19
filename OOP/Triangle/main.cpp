#include <iostream>
#include "triangle.hpp"

int main() {
	Triangle t;
	Triangle t2(2, 5);
	Triangle t1000(t2);

	std::cout << t << ", " << t2 << ", " << t1000 << '\n';
	
	return 0;
}
