#include <stdio.h>

int main() {
	int x[3] = {5, 12, 9};
	printf("%p %p %p\n", x, &x, &x[0]);

	int i;
	/*
	for (i=0; i<3; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	*/
	for (i=0; i<3; i++) {
		printf("%d ", *(x+i));
	}
	printf("\n");

	return 0;
}
