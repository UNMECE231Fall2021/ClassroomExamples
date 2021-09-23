#include <iostream>
#include <string>

int main() {
	std::string s = "Hello";
	std::string s2("world!");

	std::cout << s << ' ' << s2 << '\n';

	std::cout << s.size() << ' ' << s.empty() << '\n';
	s.clear();
	std::cout << s.size() << ' ' << s.empty() << '\n';

	return 0;
}
