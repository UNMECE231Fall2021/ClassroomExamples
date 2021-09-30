#include <iostream>

class Vector {
	private:
		double *_elem;
		int _size;
	public:
		Vector() : _elem{nullptr}, _size{0} {}

		Vector(std::initializer_list<double> lst) : _elem{new double[lst.size()]}, 
			_size{(int) lst.size()} {
				std::copy(lst.begin(), lst.end(), _elem);
		}

		Vector(const Vector &v) : _elem{new double[v.size()]}, _size{v.size()} {
			for (int i=0; i<v.size(); ++i) {
				_elem[i] = v._elem[i];
			}
		}

		~Vector() {
			if (_elem != nullptr) {
				delete[] _elem;
			}
		}

		int size() const {
			return _size;
		}

		double& operator[](int i)  {
			return _elem[i];
		}
};

int main() {
	Vector a{6.3, 8.5, 9.2};
	Vector b(a);
	// Vector b = a;

	return 0;
}
