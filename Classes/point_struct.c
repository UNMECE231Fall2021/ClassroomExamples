#include <iostream>

struct _point {
	int x;
	int y;
	int z;

	void (*init) (struct _point *, int, int, int);
	void (*print) (struct _point);
};

//typedef struct _point Point;

void init_point(struct _point *p, int x, int y, int z) {
	p->x = x;
	p->y = y;
	p->z = z;
}

void print_point(struct _point p) {
	std::cout << p.x << ", " << p.y << ", " << p.z << '\n';
}

int main() {
	struct _point a = {0, 0, 1};
	struct _point b;
	b.print = &print_point;
	b.init = &init_point;
	b.init(&b, 5, 12, -1);
	b.print(b);
	//init_point(&b, 5, 12, -1);
	/*
	b.x = 5;
	b.y = 12;
	b.z = -1;
	*/
	//print_point(b);

	return 0;
}
