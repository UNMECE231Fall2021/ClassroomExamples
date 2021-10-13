#ifndef DERIVED_CUBE_HPP
#define DERIVED_CUBE_HPP

#include <iostream>
#include "rectangle.hpp"

class Cube : public Rectangle {
	private:
		int _depth;
		int _surface_area;
		int _volume;

		void calc_surface_area();
		void calc_volume();

	public:
		Cube();
		Cube(int length, int width, int depth);
		Cube(const Cube &c);

		int depth() const;
		int surface_area() const;
		int volume() const;

		void set_length(int length) override;
		void set_width(int width) override;
		void set_depth(int depth);

		Cube &operator=(const Cube &c);
};

std::ostream &operator<<(std::ostream &out, const Cube &c);

#endif // DERIVED_CUBE_HPP
