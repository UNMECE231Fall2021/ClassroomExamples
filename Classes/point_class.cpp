#include <iostream>
#include <cassert>

class Point {
	private:
		int _x;
		int _y;
		int _z;
	public:
		Point() : _x{0}, _y{0}, _z{0} {}
		Point(int x, int y, int z) : _x{x}, _y{y}, _z{z} {}
		Point(const Point &p) : _x{p._x}, _y{p._y}, _z{p._z} {}
		~Point() {}

		void set_x(int x) {
			/*
			if (x < 0) {
				return;
			}
			*/
			_x = x;
		}

		void set_y(int y) {
			_y = y;
		}

		void set_z(int z) {
			_z = z;
		}

		int x() const {
			return _x;
		}

		int y() const {
			return _y;
		}

		int z() const {
			return _z;
		}

		void print() const {
			std::cout << x() << ' ' << y() << ' ' << z() << '\n';
		}

		Point add(const Point &p) {
			Point temp(x() + p.x(), y() + p.y(), z() + p.z());
			return temp;
		}
		Point sub(const Point &p) {
			Point temp(x() - p.x(), y() - p.y(), z() - p.z());
			return temp;
		}
		Point mult(const Point &p) {
			Point temp(x() * p.x(), y() * p.y(), z() * p.z());
			return temp;
		}
		Point div(const Point &p) {
			assert(p.x() != 0);
			assert(p.y() != 0);
			assert(p.z() != 0);
			Point temp(x() / p.x(), y() / p.y(), z() / p.z());
			return temp;
		}

		Point operator+(const Point &p) {
			return add(p);
		}

		Point operator-(const Point &p) {
			return sub(p);
		}

		Point operator*(const Point &p) {
			return mult(p);
		}

		Point operator/(const Point &p) {
			return div(p);
		}

		Point &operator=(const Point &p) {
			if (this == &p) {
				return *this;
			}
			_x = p._x;
			_y = p._y;
			_z = p._z;
			return *this;
		}

		friend std::ostream &operator<<(std::ostream &out, const Point &p);
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
	out << p.x() << ' ' << p.y() << ' ' << p.z();
	return out;
}

int main() {
	Point p(4, -9, 1);
	Point q = p;

	q.set_x(5);
	q.print();

	//Point r(q.add(p));
	Point r = q = p;
	r.print();

	std::cout << r << q << p;

	return 0;
}
