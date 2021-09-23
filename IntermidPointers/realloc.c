#include <stdio.h>
#include <stdlib.h>

int main() {
	float *x = (float *)malloc(3* sizeof(float));
	int i;
	for (i=0; i<3; i++) {
		x[i] = i * i;
	}

	for (i=0; i<3; i++) {
		printf("%f\n", x[i]);
	}

	//I do stuff here

	x = (float *) realloc(x, 5 * sizeof(float));
 
	for (i; i<5; i++) {
		x[i] = i * i;
	}

	for (i=3; i<5; i++) {
		printf("%f\n", x[i]);
	}

	free(x);
	return 0;
}
