#ifndef G_STACK_HPP
#define G_STACK_HPP
#include <iostream>

template <typename T>
class Stack {
	private:
		size_t _size;
		T *_values;
	public:
		Stack() : _size{0}, _values{nullptr} {}
		Stack(T value) : _size{1}, _values{nullptr} {
			_values = new T(value);
		}

		Stack(const Stack &s) {
			if (s.size() == 0) {
				_size = 0;
				_values = nullptr;
			}
			else {
				_size = s.size();
				_values = new T[s.size()];
				for (int i=0; i<s.size(); ++i) {
					*(_values + i) = *(s._values + i);
				}
			}
		}
		~Stack() {
			if (_size == 1) {
				delete _values;
			}
			else {
				delete[] _values;
			}
		}

		size_t size() const {
			return _size;
		}

		T top() const {
			return *(_values + size() - 1);
		}

		void push(T value) {
			if (empty()) {
				_size++;
				_values = new T(value);
			}
			else {
				size_t copy_size = size();
				T *copy_values = new T[copy_size];

				for (int i=0; i<copy_size; ++i) {
					*(copy_values + i) = *(_values + i);
				}

				delete[] _values;
				_values = new T[copy_size+1];

				int i;
				for(i=0; i<copy_size; ++i) {
					*(_values + i) = *(copy_values + i);
				}
				*(_values + i) = value;

				_size++;
				delete[] copy_values;
			}
		}

		void pop() {
			if (empty()) {
				return;
			}
			else if (_size == 1) {
				delete _values;
				_values = nullptr;
				_size = 0;
			}
			else {
				size_t copy_size = size();
				T *copy_values = new T[copy_size];

				for (int i=0; i<copy_size; ++i) {
					*(copy_values + i) = *(_values + i);
				}

				delete[] _values;
				_values = new T[copy_size-1];

				int i;
				for(i=0; i<copy_size-1; ++i) {
					*(_values + i) = *(copy_values + i);
				}

				_size--;
				delete[] copy_values;
			}
		}

		void print() const {
			for (int i=0; i<size(); ++i) {
				//std::cout << *(_values + i) << ' ';
				std::cout << _values[i] << ' ';
			}
			std::cout << '\n';
		}

		bool empty() const {
			return (_values == nullptr) && (_size == 0);
		}

		bool search(T search_value) {
			for (int i=0; i<size(); ++i) {
				if (search_value == *(_values + i)) {
					return true;
				}
			}
			return false;
		}

		// a = b where a != b
		// a = a where a == a
		Stack &operator=(const Stack &s) {
			if (this == &s) {
				return *this;
			}
			if (s.empty()) {
				if (empty()) {
					return *this;
				}
				if (size() == 1) {
					delete _values;
				}
				else {
					delete[] _values;
				}
				_size = 0;
				_values = nullptr;
			}
			else if (s.size() == 1) {
				if (size() == 1) {
					delete _values;
				}
				else {
					delete[] _values;
				}
				_values = new T(*_values);
				_size = 1;
			}
			else {
				if (size() == 1) {
					delete _values;
				}
				else {
					delete[] _values;
				}
				_values = new T[s.size()];

				for (int i=0; i<s.size(); ++i) {
					*(_values + i) = *(s._values + i);
				}
				_size = s.size();
			}

			return *this;
		}
  
		template <typename A>
		friend std::ostream &operator<<(std::ostream &out, const Stack<A> &s);

		// lhs == rhs
		template <typename B>
		friend bool operator==(const Stack<B> &lhs, const Stack<B> &rhs);

		template <typename Thing>
		friend bool operator!=(const Stack<Thing> &lhs, const Stack<Thing> &rhs);
};

template <typename A>
std::ostream &operator<<(std::ostream &out, const Stack<A> &s) {
	for (int i=0; i<s.size(); ++i) {
		out << *(s._values + i) << ' ';
	}
	return out;
}

template <typename B>
bool operator==(const Stack<B> &lhs, const Stack<B> &rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	for (int i=0; i<lhs.size(); ++i) {
		if ( (*(lhs._values + i)) != (*(rhs._values + i)) ) {
			return false;
		}
	}
	return true;
}

template <typename Thing>
bool operator!=(const Stack<Thing> &lhs, const Stack<Thing> &rhs) {
	return !(lhs == rhs);
}

#endif // G_STACK_HPP
