#ifndef G_QUEUE_HPP
#define G_QUEUE_HPP
#include <initializer_list>
#include <iostream>

template <typename T>
class Queue {
	private:
		size_t _size;
		T *_values;
	public:
		Queue() : _size{0}, _values{nullptr} {}
		Queue(T value) : _size{1}, _values{nullptr} {
			_values = new T(value);
		}

		Queue(std::initializer_list<T> &lst) : _size{lst.size()}, _values{nullptr} {
			_values = new T[_size];
			for (int i=0; i<_size; ++i) {
				*(_values + i) = lst[i];
			}
		}

		Queue(const Queue<T> &s) {
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
		~Queue() {
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

		T back() const {
			return *(_values + size() - 1);
		}

		T front() const {
			return *(_values);
		}

		void enqueue(T value) {
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

		void dequeue() {
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
					*(_values + i) = *(copy_values + (i+1));
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
		Queue<T> &operator=(const Queue<T> &s) {
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
		friend std::ostream &operator<<(std::ostream &out, const Queue<A> &s);

		// lhs == rhs
		template <typename B>
		friend bool operator==(const Queue<B> &lhs, const Queue<B> &rhs);

		template <typename Thing>
		friend bool operator!=(const Queue<Thing> &lhs, const Queue<Thing> &rhs);
};

template <typename A>
std::ostream &operator<<(std::ostream &out, const Queue<A> &s) {
	for (int i=0; i<s.size(); ++i) {
		out << *(s._values + i) << ' ';
	}
	return out;
}

template <typename B>
bool operator==(const Queue<B> &lhs, const Queue<B> &rhs) {
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
bool operator!=(const Queue<Thing> &lhs, const Queue<Thing> &rhs) {
	return !(lhs == rhs);
}

#endif // G_QUEUE_HPP
