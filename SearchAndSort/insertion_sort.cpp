#include <iostream>
#include <vector>

template <typename T>
void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

// n ( 1 + 2 + 3 + ... + n-1) = (n * (n-1)) / 2 ~ n^2

template <typename T>
void insertion_sort(std::vector<T> &v) {
	int size = v.size();
	for (int i=1; i<size; ++i) {
		for (int j=0; j<i+1; ++j) {
			if (v[i] < v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
}

int main() {
	std::vector<int> x = {56, 2, 14, 9, 7};

	return 0;
}
