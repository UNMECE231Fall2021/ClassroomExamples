#include <stdio.h>
#include <stdlib.h>

struct _complex {
	double *real;
	double *imag;
};
typedef struct _complex Complex;

int main() {
	int i = 0;
	double x[2] = {5.6, 7.8};

	int *a = (int *)malloc(1 * sizeof(int));
	double *b = (double *)calloc(2, sizeof(double));
	// double *b = (double *)malloc(2 * sizeof(double));

	*a = 0;
	printf("%lf %lf\n", b[0], b[1]);

	Complex q;
	q.real = (double *)malloc(1 * sizeof(double));
	q.imag = (double *)calloc(1, sizeof(double));
	printf("%lf, %lf\n", *(q.real), *(q.imag));

	Complex *z = (Complex *)malloc(1 * sizeof(Complex));
	z->real = (double *)calloc(1, sizeof(double));
	z->imag = (double *)malloc(1 * sizeof(double));
	printf("%lf, %lf\n", *(z->real), *(z->imag));

	free(a);
	free(b);
	free(q.real);
	free(q.imag);
	free(z->real);
	free(z->imag);
	free(z);

	return 0;
}
