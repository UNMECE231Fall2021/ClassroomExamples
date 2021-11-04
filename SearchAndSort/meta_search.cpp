#include <iostream>
#include <vector>

template <typename T>
int meta_linear_search(const std::vector<T> &v, T search_value) {
	int iter = 1;
	for (const auto &i : v) {
		if (search_value == i) {
			return iter;
		}
		iter++;
	}
	return iter;
}

template <typename T>
int meta_binary_search(const std::vector<T> &v, T search_value) {
	int begin=0;
	int end = v.size() - 1;
	int iter=1;

	while (true) {
		int mid = (begin + end) / 2;
		if (v[mid] == search_value) {
			return iter;
		}

		if (v[mid] > search_value) {
			// Chops off right side
			end = mid - 1;
		}
		else {
			// Chops off left side
			begin = mid + 1;
		}

		if (mid == end) {
			return iter;
		}
		iter++;
	}
	return iter;
}

int main() {
	std::vector<int> x = {3, 5, 8, 9, 14, 19, 24, 37, 45};

	std::cout << "binary search: " << meta_binary_search(x, 45) << '\n';
	std::cout << "linear search: " << meta_linear_search(x, 45) << '\n';
	return 0;
}
