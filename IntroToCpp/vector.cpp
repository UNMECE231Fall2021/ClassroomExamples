#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << v.size() << '\n';

	v.push_back(9);
	std::cout << v.size() << '\n';

	v.pop_back();
	std::cout << v.size() << '\n';

	/*
	for (int i=0; i<v.size(); ++i) {
		std::cout << v[i] << ' ';
	}
	for (auto i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << ' ';
	}
	*/

	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	for(auto &x : v) {
		x += 1;
	}

	std::vector<std::string> s = {"Hello", "how", "are", "you", "?"};

	for (const auto &z : s) {
		std::cout << z << ' ';
	}
	std::cout << std::endl;

	return 0;
}
