#include "pyramid.hpp"

Pyramid::Pyramid() : Triangle(), Shape3D() {}

Pyramid::Pyramid(int base, int height, int depth) : Triangle(base, height) {
	set_depth(depth);
}

Pyramid::Pyramid(const Pyramid& p) : Triangle(p), Shape3D(p) {}

Pyramid::~Pyramid() {}

void Pyramid::set_base(int base) {
	// Comes from Triangle
	Triangle::set_base(base);
	// Comes from Shape3D
	calc_surface_area();
	calc_volume();
}

void Pyramid::set_height(int height) {
	Triangle::set_height(height);
	calc_surface_area();
	calc_volume();
}

void Pyramid::set_depth(int depth) {
	Shape3D::set_depth(depth);
	calc_surface_area();
	calc_volume();
}

void Pyramid::calc_surface_area() {
	double bottom_area = base() * depth();
	double forward_back_area = area() * 2;
	double side_area = depth() * height() * 2;
	_surface_area = bottom_area + forward_back_area + side_area;
}

void Pyramid::calc_volume() {
	_volume = (1/3.0) * area() * depth();
}

Pyramid& Pyramid::operator=(const Pyramid& p) {
	if (this == &p) {
		return *this;
	}
	_base = p._base;
	set_height(p._height);
	set_depth(p._depth);
	/*
	_area = p._area;
	_depth = p._depth;
	_surface_area = p._surface_area;
	_volume = p._volume;
	*/
	return *this;
}

bool Pyramid::operator==(const Pyramid& p) {
	return (_base == p._base) && (_height == p._height) &&\
				   (_depth == p._depth);
}

bool Pyramid::operator!=(const Pyramid& p) {
	return !(*this == p);
}

std::ostream& operator<<(std::ostream& out, const Pyramid& p) {
	out << p._base << ' ' << p._height << ' ' << p._depth << ' ';
	out << p._surface_area << ' ' << p._volume;
	return out;
}
