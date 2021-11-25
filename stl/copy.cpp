#include <iostream>
#include <vector>

template<typename IIter, typename OIter>
OIter general_copy(IIter first, IIter last, OIter res) {
	for(; first!=last; ++first, ++res) {
		*res = *first;
	}
	return res;
}

template <typename T>
void print_vector(const std::vector<T> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::vector <double> a = {8.3, 4.7, 1.6, 4.9};
	std::vector <double> b = {3.8, 7.4, 6.1, 9.4, 2.3, 4.4};

	print_vector(b);
	//auto return_iter = general_copy(a.begin(), a.end(), b.begin()+1);
	auto return_iter = std::copy(a.begin(), a.end(), b.begin()+1);
	print_vector(b);
	if (return_iter != b.end()) {
		std::cout << "B was not fully overwritten!\n";
	}

	return 0;
}
