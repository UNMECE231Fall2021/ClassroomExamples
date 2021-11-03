#include <iostream>
#include <vector>

template <typename T>
bool linear_search(const std::vector<T> &v, T search_value) {
	/*
	for (int i=0; i<v.size(); ++i) {
		if (search_value == v[i]) {
			return true;
		}
	}
	for (auto i=v.begin(); i!=v.end(); ++i) {
		if (search_value == *i) {
			return true;
		}
	}
	*/
	for (const auto &i : v) {
		if (search_value == i) {
			return true;
		}
	}
	return false;
}

int main() {
	std::vector<float> x = {3.3, 5.435, 9.245};
	std::cout << linear_search(x, 9.245f) << '\n';

	return 0;
}
