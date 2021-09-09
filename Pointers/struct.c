#include <stdio.h>

struct _date {
	int month;
	int day;
	int year;
};
typedef struct _date Date;

struct _time {
	int second;
	int minute;
	int hour;
};
typedef struct _time Time;

struct _dnt {
	Date d;
	Time t;
};
typedef struct _dnt DateAndTime;

struct _stuff {
	double thing; // 8
	float x; // 4
	float y; // 4
	char c; //1
	DateAndTime dnt; // 24
};

typedef struct _stuff Stuff;


//typedef float fl;

void print_date(Date x) {
	printf("Month: %d, Day: %d, Year: %d\n", x.month, x.day, x.year);
}

Date init_date(int m, int d, int y) {
	Date q = {m, d, y};
	return q;
}

int main() {
	Date d = {1, 12, 2021};
	Date d2 = {1, 17, 2022};

	DateAndTime today = {{9, 9, 2021}, {30, 39, 11}};
	printf("Minute: %d\n", today.t.minute);

	Stuff s = {72.5, 1.2f, 3.4f, 'q', {{10, 30, 2077}, {45, 27, 11}}};
	printf("%d\n", s.dnt.d.year);

	return 0;
}
