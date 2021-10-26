#include "shape3D.hpp"

Shape3D::Shape3D() : _depth{0}, _surface_area{0}, _volume{0} {}

Shape3D::Shape3D(const Shape3D &s) : _depth{s._depth}, 
	_surface_area{s._surface_area}, _volume{s._volume} {}

Shape3D::~Shape3D() {}

int Shape3D::depth() const {
	return _depth;
}

float Shape3D::volume() const {
	return _volume;
}

float Shape3D::surface_area() const {
	return _surface_area;
}

void Shape3D::set_depth(int depth) {
	if (depth > 0) {
		_depth = depth;
	}
}
