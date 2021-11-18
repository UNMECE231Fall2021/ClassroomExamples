#include <iostream>
#include "Stack.hpp"

int main() {
	Stack<float> s1;
	Stack<int> s2(5);
	//std::cout << s2.top() << ", " << s2.size() << '\n'; // 5, 1
	s2.print(); // 5

	s2.push(1); // 5 1
	s2.push(12); // 5 1 12
	s2.push(2); // 5 1 12 2

	Stack<int> s3(s2); // 5 1 12 2
	//std::cout << s3 << '\n'; // 5 1 12 2

	s3.pop(); // 5 1 12
	std::cout << s3 << '\n'; // 5 1 12

	/*
	if (s1.empty()) {
		std::cout << "s1 is empty!\n";
	}
	*/

	s2.pop(); // 5 1 12
	s2.pop(); // 5 1 
	s2.pop(); // 5 
	s2.pop(); // NOTHING

	/*
	if (s2.empty()) {
		std::cout << "s2 is empty!\n";
	}
	*/

	std::cout << s3.top() << '\n'; // 12
	std::cout << s3.search(1) << ", " << s3.search(7) << '\n'; // 1, 0

	if (s2 != s3) {
		std::cout << "s2 and s3 are not equal!\n";
	}

	s2 = s3;
	if (s2 == s3) {
		std::cout << "s2 and s3 are equal!\n";
	}

	Stack<int> s4(s3);
	if (s4 == s3) {
		std::cout << "s4 and s3 are equal!\n";
	}

	return 0;
}
