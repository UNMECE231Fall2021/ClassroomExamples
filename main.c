#include <stdio.h>
#include "Maths.h"

int main() {
	double a = 1.3, b = 5.1;

	double res_add = add(a, b);
	double res_mult = mult(a, b);
	double res_sq = sq(a);

	printf(" %.4lf\n %.4lf\n %.4lf\n", res_add, res_mult, res_sq);

	return 0;
}
