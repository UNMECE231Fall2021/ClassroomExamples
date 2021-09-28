#include <iostream>

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

		void print() {
			std::cout << x() << ' ' << _y << ' ' << z() << '\n';
		}
};

int main() {
	Point q;
	q.set_x(5);

	q.print();

	return 0;
}
