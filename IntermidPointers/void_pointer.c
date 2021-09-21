#include <stdio.h>

struct _bleh {
	int z;
};

int main() {
	int a = 1;
	float b = 2.0f;
	double c = 3.0;
	char d = 'q';
	struct _bleh f = {5};

	void *p;

	p = &a;
	printf("%d\n", *(int *)p);
	p = &b;
	printf("%d\n", *(float *)p);
	p = &c;
	printf("%lf\n", *(double *)p);
	p = &d;
	printf("%c\n", *(char *)p);
	p = &f;
	printf("%d\n", (*(struct _bleh *)p).z);

	return 0;
}
