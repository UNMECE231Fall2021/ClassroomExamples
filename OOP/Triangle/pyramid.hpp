#ifndef DERIVED_PYRAMID_HPP
#define DERIVED_PYRAMID_HPP

#include <iostream>
#include "triangle.hpp"
#include "shape3D.hpp"

class Pyramid : public Triangle, public Shape3D {
	public:
		Pyramid();
		Pyramid(int base, int height, int depth);
		Pyramid(const Pyramid& p);
		~Pyramid();

		// Comes from Triangle
		void set_base(int base) override;
		void set_height(int height) override;
		
		// Comes from Shape3D
		void set_depth(int depth) override;

		// Override virtual methods
		void calc_surface_area() override;
		void calc_volume() override;

		Pyramid& operator=(const Pyramid& p);
		bool operator==(const Pyramid& p);
		bool operator!=(const Pyramid& p);
		friend std::ostream& operator<<(std::ostream& out, const Pyramid& p);
};
// std::ostream & == std::ostream&
// int * == int*

#endif // DERIVED_PYRAMID_HPP
