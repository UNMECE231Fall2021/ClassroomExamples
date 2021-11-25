#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

template <typename Iter, typename Val>
Val acc(Iter first, Iter last, Val res) {
	for (auto i=first; i!=last; ++i) {
		res += *i;
	}
	return res;
}

template <typename T>
double mean(const std::vector<T> &v) {
	assert(v.size() != 0);
	return (std::accumulate(v.begin(), v.end(), 0.0) / v.size());
}


int main() {
	std::vector<int> x = {1, 2, 3, 4, 5, 6};
	std::cout << acc(x.begin(), x.end(), 0) << '\n';
	std::cout << std::accumulate(x.begin(), x.end(), 10) << '\n';

	std::cout << mean(x) << '\n';

	return 0;
}
