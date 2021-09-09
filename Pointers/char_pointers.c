#include <stdio.h>

int main() {
	char z[3] = {'Y', 'o', '\0'};
	char str[] = "hey";
	//printf("%c\n", z[100]);
	char const s[] = "there, what's up";
	//printf("%s\n", str);
	//printf("%c\n", str[0]);

	//printf("%p, %p, %p\n", str, &str, &str[0]);

	char *c = "Hello";
	char *q = str;

	//printf("%p, %p, %p\n", c, &c, &(c[0]));

	*q = 'y';
	printf("%s\n", str);
	printf("%s\n", c);
	printf("%s\n", c);
	printf("%c\n", *c);
	// *c == c[0]
	// *c+1 == c[1]


	return 0;
}
