#include <stdio.h>
#include <stdlib.h>

struct _list {
	int value;
	struct _list *next;
};

typedef struct _list List;

struct _complex {
	double real;
	double imag;
};
typedef struct _complex Complex;

int main() {
	int i = 0;
	double x[2] = {5.6, 7.8};

	int *a = (int *)malloc(1 * sizeof(int));
	// malloc(4)
	double *b = (double *)malloc(2 * sizeof(double));
	// malloc(16)

	List *c = (List *)malloc(1 * sizeof(List));

	Complex q;
	Complex *d = (Complex *)malloc(1 * sizeof(Complex));

	free(a);
	free(b);
	free(c);
	free(d);

	return 0;
}
