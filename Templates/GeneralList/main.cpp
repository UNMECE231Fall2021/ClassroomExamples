#include <iostream>
#include "GenericList.hpp"

template <typename T>
void check_empty(const SList<T> &il) {
	if (il.empty()) {
		std::cout << "The list is empty!\n";
	}
	else {
		std::cout << "The list is not empty!\n";
	}
}

int main() {
	SList<int> ilist;

	check_empty(ilist);

	ilist.push_front(1);
	ilist.push_front(0);

	check_empty(ilist);

	ilist.push_back(5);

	//std::cout << ilist.front() << ' ' << ilist.back() << ' ' << ilist.size();
	//std::cout << '\n' << ilist << '\n';
	SList<int> ilist2(ilist);
	ilist2.pop_front();
	ilist2.push_back(3);
	ilist2.push_back(4);
	ilist2.push_back(9);
	ilist2.pop_back();
	std::cout << ilist2 << '\n'; // 1 5 3 4
	ilist2 = ilist2;
	std::cout << ilist2 << '\n'; // 0 1 5

	return 0;
}
