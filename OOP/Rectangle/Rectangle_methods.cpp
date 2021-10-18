#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle() : _length{1}, _width{1} {
	calc_area();
	calc_perimeter();
}

Rectangle::Rectangle(int length) : _length{1}, _width{1} {
	set_length(length);
	calc_area();
	calc_perimeter();
}

Rectangle::Rectangle(int length, int width) : _length{length}, _width{width} { 
	calc_area();
	calc_perimeter();
}

Rectangle::Rectangle(const Rectangle &r) : _length{r._length}, _width{r._width}, _area{r._area},
	_perimeter{r._perimeter} { }

Rectangle::~Rectangle() {}

int Rectangle::length() const {
	return _length;
}

int Rectangle::width() const {
	return _width;
}

void Rectangle::set_length(int length) {
	//assert(length>0);
	if (length > -1) {
		_length = length;
		calc_area();
		calc_perimeter();
	}
}

void Rectangle::set_width(int width) {
	//assert(width>0);
	if (width > -1) {
		_width = width;
		calc_area();
		calc_perimeter();
	}
}

void Rectangle::calc_area() {
	_area = length() * width();
}

void Rectangle::calc_perimeter() {
	_perimeter = 2 * (length() + width());
}

Rectangle &Rectangle::operator=(const Rectangle &r) {
	if (this == &r) {
		return *this;
	}
	_length = r._length;
	_width = r._width;
	_area = r._area;
	_perimeter = r._perimeter;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &r) {
	out << r._length << ' ' << r._width << ' ' << r._area << ' ' << r._perimeter;
	return out;
}
