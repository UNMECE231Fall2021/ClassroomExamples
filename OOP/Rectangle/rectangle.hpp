#ifndef BASE_RECTANGLE_HPP
#define BASE_RECTANGLE_HPP

#include <iostream>

class Rectangle {
	protected:
		int _length;
		int _width;
		int _area;
		int _perimeter;

		void calc_area();
		void calc_perimeter();

	public:
		Rectangle();
		Rectangle(int length);
		Rectangle(int length, int width);
		Rectangle(const Rectangle &r);
		virtual ~Rectangle();

		int length() const;
		int width() const;
		int area() const;
		int perimeter() const;

		virtual void set_length(int length);
		virtual void set_width(int width);

		Rectangle &operator=(const Rectangle &r);

		friend std::ostream &operator<<(std::ostream &out, const Rectangle &r);
};

#endif // BASE_RECTANGLE_HPP
