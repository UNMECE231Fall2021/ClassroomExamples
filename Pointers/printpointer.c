#include <stdio.h>

int main() {
	int x = 5;
	int z = 1;

	int *y;
	y = &x;

	printf("%p, %p\n", &x, &z);

	printf("%p, %d\n", y, *y);

	return 0;
}
