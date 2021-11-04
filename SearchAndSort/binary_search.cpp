#include <iostream>
#include <vector>

template <typename T>
bool binary_search(const std::vector<T> &v, T search_value) {
	int begin=0;
	int end = v.size() - 1;

	while (true) {
		int mid = (begin + end) / 2;
		if (v[mid] == search_value) {
			return true;
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
			return false;
		}
	}
	return false;
}

int main() {
	std::vector<int> x = {3, 5, 8, 9, 14, 19, 24, 37, 45};

	std::cout << binary_search(x, 3) << '\n';
	return 0;
}
