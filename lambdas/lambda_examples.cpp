#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(const std::vector<T> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int sq(int x) {
	return x * x;
}

int cu(int x) {
	return x * x * x;
}

template <typename Iter, typename Function>
void ForEach(Iter begin, Iter end, Function f) {
	// 1, 2, 3, 4, 5
	for(auto i = begin; i!=end; ++i) {
		f(*i);
	}
	// f(1), f(2), ..., f(5)
}

int main() {
	std::vector<int> v = {3, 4, 6, 9, 11};
	std::vector<int> v_sq = v;
	std::vector<int> v_cu = v;
	std::vector<int> v_offset = v;

	//print_vector(v_sq);
	auto square = [](int &x){x = x * x;};
	std::for_each(v_sq.begin(), v_sq.end(), square);

	auto print = [](const int &x){std::cout << x << ' ';};
	std::for_each(v_sq.begin(), v_sq.end(), print);
	std::cout << '\n';
	//print_vector(v_sq); 

	auto cube = [](int &x){x = x * x * x;};
	std::for_each(v_cu.begin(), v_cu.end(), cube);
	print_vector(v_cu);

	// [Capture clause](Parameters){Function body};
	// = -> const copies of local variables
	// & -> references of local variables
	// var -> const copy of local variable var
	// &var -> reference of local variable var
	int offset = 5;
	auto sq_offset = [offset](int &x) {
		x = (x * x) + offset;
	};
	std::for_each(v_offset.begin(), v_offset.end(), sq_offset);
	print_vector(v_offset);

	return 0;
}
