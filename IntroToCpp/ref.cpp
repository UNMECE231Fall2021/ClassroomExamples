#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

void square_vector(std::vector<int> &v) {
	for (auto &x : v) {
		x = x * x;
	}
}

void ptr_square_vector(std::vector<int> *v) {
	for (auto i = (*v).begin(); i != (*v).end(); ++i) {
		*i = (*i) * (*i);
	}
}

int main() {
	std::vector<int> z = {2, 4, 5, 6, 9};

	print_vector(z);
	square_vector(z);
	//ptr_square_vector(&z);
	print_vector(z);

	return 0;
}
