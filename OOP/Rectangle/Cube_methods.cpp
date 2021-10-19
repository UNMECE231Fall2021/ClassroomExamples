#include "cube.hpp"

Cube::Cube() : Rectangle(), _depth{1}, _surface_area{6}, _volume{1} { }

Cube::Cube(int length, int width, int depth) : Rectangle(length, width), _depth{depth} {
	calc_surface_area();
	calc_volume();
}

Cube::Cube(const Cube &c) : Rectangle(c), _depth{c._depth}, 
	_surface_area{c._surface_area}, _volume{c._volume} {}

int Cube::depth() const {
	return _depth;
}

int Cube::surface_area() const {
	return _surface_area;
}

int Cube::volume() const {
	return _volume;
}

void Cube::set_length(int length) {
	Rectangle::set_length(length);
	calc_surface_area();
	calc_volume();
}

void Cube::set_width(int width) {
	Rectangle::set_width(width);
	calc_surface_area();
	calc_volume();
}

void Cube::set_depth(int depth) {
	if (depth > -1) {
		_depth = depth;
	}
	calc_surface_area();
	calc_volume();
}

void Cube::calc_surface_area() {
	_surface_area = 2 * (length() * width()) +\
					2 * (length() * depth()) +\
					2 * (width() * depth());
}

void Cube::calc_volume() {
	_volume = length() * width() * depth();
}

Cube &Cube::operator=(const Cube &c) {
	if (this == &c) {
		return *this;
	}
	_length = c._length;
	_width = c._width;
	_area = c._area;
	_perimeter = c._perimeter;
	_depth = c._depth;
	_surface_area = c._surface_area;
	_volume =c._volume;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Cube &c) {
	out << c.length() << ' ' << c.width() << ' ' << c.depth() << ' ' << c.surface_area() 
		<< ' ' << c.volume();
	return out;
}
