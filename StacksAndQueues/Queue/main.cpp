#include <iostream>
#include "Queue.hpp"

int main() {
	Queue<float> s1;
	Queue<int> s2(5);

	s2.enqueue(1); // 5 1
	s2.enqueue(12); // 5 1 12
	s2.enqueue(2); // 5 1 12 2

	Queue<int> s3(s2); // 5 1 12 2
	std::cout << s3 << '\n'; // 5 1 12 2

	s3.dequeue(); // 1 12 2
	std::cout << s3 << '\n'; // 1 12 2
	std::cout << s3.front() << ' ' << s3.back() << '\n'; // 1 2

	s2.dequeue(); // 1 12 2
	s2.print();
	s2.dequeue(); // 12 2 
	s2.print();
	s2.dequeue(); // 2
	s2.print();
	s2.dequeue(); // NOTHING

	/*
	if (s2.empty()) {
		std::cout << "s2 is empty!\n";
	}
	*/

	std::cout << s3.search(1) << ", " << s3.search(7) << '\n'; // 1, 0

	if (s2 != s3) {
		std::cout << "s2 and s3 are not equal!\n";
	}

	s2 = s3;
	if (s2 == s3) {
		std::cout << "s2 and s3 are equal!\n";
	}

	Queue<int> s4(s3);
	if (s4 == s3) {
		std::cout << "s4 and s3 are equal!\n";
	}

	Queue<float> s5{3.14, 42.0, 36.0};

	return 0;
}
