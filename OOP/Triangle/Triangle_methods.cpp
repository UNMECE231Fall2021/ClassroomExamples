#include "triangle.hpp"
#include <cassert>
#include <cmath>

Triangle::Triangle() : _base{1}, _height{1}, _area{0.5f}, _perimeter{3.23607f}
{}

Triangle::Triangle(int base, int height) : _base{1}, _height{1} {
	set_base(base);
	set_height(height);
	calc_area();
	calc_perimeter();
}

Triangle::Triangle(const Triangle &t) : _base{t._base}, _height{t._height},
		_area{t._area}, _perimeter{t._perimeter} { }

Triangle::~Triangle() {}

void Triangle::set_base(int base) {
	if (base > 0) {
		_base = base;
	}
}

void Triangle::set_height(int height) {
	assert(height > 0);
	_height = height;
}

int Triangle::base() const {
	return _base;
}

int Triangle::height() const {
	return _height;
}

void Triangle::calc_area() {
	_area = (1/2.0) * base() * height();
}

void Triangle::calc_perimeter() {
	float hyp = (0.5 * base()) * (0.5 * base()) + (height() * height());
	hyp = sqrt(hyp);
	_perimeter = base() + (2.0 * hyp);
}

std::ostream &operator<<(std::ostream &out, const Triangle &t) {
	out << t._base << ' ' << t._height << ' ' << t._area << ' ';
	out << t._perimeter;
	return out;
}
