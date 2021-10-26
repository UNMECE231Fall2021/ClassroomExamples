#ifndef BASE_TRIANGLE_HPP
#define BASE_TRIANGLE_HPP

#include <iostream>

class Triangle {
	private:
		void calc_area();
		void calc_perimeter();

	protected:
		int _base;
		int _height;
		float _area;
		float _perimeter;

	public:
		Triangle();
		Triangle(int base, int height);
		Triangle(const Triangle &t);
		virtual ~Triangle();

		int base() const;
		int height() const;
		float area() const;
		float perimeter() const;

		virtual void set_base(int base);
		virtual void set_height(int height);

		Triangle &operator=(const Triangle &t);

		bool operator==(const Triangle &t);
		bool operator!=(const Triangle &t);

		friend std::ostream &operator<<(std::ostream &out, const Triangle &t);
};

#endif // BASE_TRIANGLE_HPP
