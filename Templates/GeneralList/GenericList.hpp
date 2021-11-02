#ifndef GENERAL_LIST_HPP
#define GENERAL_LIST_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class SList {
	private:
		struct _list {
			T value;
			struct _list *next;
		};
		typedef struct _list List;

		List *_front;
		List *_back;
		size_t _size;

		void reccopy(const List *ptr) {
			if (ptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}

	public:
		SList() : _front{nullptr}, _back{nullptr}, _size{0} {}
		SList(const SList &list) : _front{nullptr}, _back{nullptr}, _size{0} {
			reccopy(list._front);
		}
		~SList() {
			while(!empty()) {
				pop_front();
			}
		}

		T front() const {
			return _front->value;
		}

		T back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		void push_front(T value) {
			List *new_node = new List;
			new_node->value = value;
		
			if (!empty()) {
				new_node->next = _front;
			}
			else {
				new_node->next = nullptr;
				_back = new_node;
			}
			_front = new_node;
			_size += 1;
		}

		void push_back(T value) {
			List *new_node = new List;
			new_node->value = value;
			if (!empty()) {
				_back->next = new_node;
				//_back = new_node;
			}
			else {
				new_node->next = nullptr;
				_front = new_node;
				//_back = new_node;
			}
			_back = new_node;
			_size += 1;
		}

		void pop_front() {
			// Linked list is empty
			if (empty()) {
				return;
			}
			List *node_to_delete = _front;
			// Linked list has only one node
			if (_front->next == nullptr) {
				_front = nullptr;
				_back = nullptr;
				//_size = 0; // 1 -> 0
			}
			// Linked list has more than one node
			else {
				_front = _front->next;
				//_size -= 1; // n -> (n-1)
			}
			_size -= 1;
			delete node_to_delete;
		}

		void pop_back() {
			if (empty()) {
				return;
			}
			List *node_to_delete = _back;
			if (_front->next == nullptr) {
				_front = nullptr;
				_back = nullptr;
			}
			else {
				List *new_back = _front;
				while(new_back->next != _back) {
					new_back = new_back->next;
				}
				new_back->next = nullptr;
				_back = new_back;
			}
			_size -= 1;
			delete node_to_delete;
		}

		bool empty() const {
			return ( (_front == nullptr) && (_back == nullptr) );
		}

		SList &operator=(const SList &l) {
			if (this == &l) { 
				return *this; 
			}
			// Empty the list
			while (!empty()) {
				pop_front();
			}
			// Copy arg data to internal class
			reccopy(l._front);
			return *this;
		}

		//friend std::ostream &operator<<(std::ostream &out, const SList &l);
		friend std::ostream &operator<<(std::ostream &out, const SList &l) {
			List *temp;
			for (temp = l._front; temp != nullptr; temp=temp->next) {
				out << temp->value << ' ';
			}
			return out;
		}
};

/*
template <typename X>
std::ostream &operator<<(std::ostream &out, const SList<X> &l) {
	//SList<X>::List *temp;
	for (auto temp = l._front; temp != nullptr; temp=temp->next) {
		out << temp->value << ' ';
	}
	return out;
}
*/

#endif // GENERAL_LIST_HPP
