#include <stdio.h>

int main() {
	int x = 5;
	int z = 1;

	int *y;
	y = &x; // & is address operator

	int *q = &x; // Does lines 7 and 8 in one line

	printf("%p, %p\n", &x, &z);
	printf("%p, %d, %p\n", y, *y, &y);

	float a = 42.0;
	float *b = &a;

	float c = (*y) * (*b);
	printf("%f\n", c);

	return 0;
}
