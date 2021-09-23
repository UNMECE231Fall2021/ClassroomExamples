#include <iostream>
#include <cstdlib>

int main() {
	int *i = (int *)malloc(5 * sizeof(int));
	if (i == NULL) {
		printf("Error allocating memory\n");
		return -1;
	}

	int *j = new int[5];
	if (j == nullptr) {
		std::cout << "Error allocating memory\n";
		return -2;
	}

	delete[] j;
	free(i);
	return 0;
}
