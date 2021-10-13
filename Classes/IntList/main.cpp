#include <iostream>
#include "IntList.hpp"

void check_empty(const IntList &il) {
	if (il.empty()) {
		std::cout << "The list is empty!\n";
	}
	else {
		std::cout << "The list is not empty!\n";
	}
}

int main() {
	IntList ilist;

	check_empty(ilist);

	ilist.push_front(1);
	ilist.push_front(0);

	check_empty(ilist);

	ilist.push_back(5);

	return 0;
}
