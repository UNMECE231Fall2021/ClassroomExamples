#include "IntList.hpp"

void IntList::reccopy(const List *ptr) {
	if (ptr) {
		reccopy(ptr->next);
		push_front(ptr->value);
	}
}

IntList::IntList() : _front{nullptr}, _back{nullptr}, _size{0} {}

IntList::IntList(const IntList &list) : _front{nullptr}, _back{nullptr}, _size{0} {
	reccopy(list._front);
}

IntList::~IntList() {
	while(!empty()) {
			pop_front();
	}
}

size_t IntList::size() const {
	return _size;
}

void IntList::push_front(int value) {
	List *new_node = new List;
	new_node->value = value;

	if (!empty()) {
		new_node->next = _front;
	}
	else {
		new_next->next = nullptr;
		_back = new_node;
	}
	_front = new_node;
	_size += 1;
}

void IntList::pop_front() {
	if (empty()) {
		return;
	}
	if (_front->next == nullptr) {
		List *node_to_delete = _front;
		_front = nullptr;
		_back = nullptr;
		_size = 0;
		delete node_to_delete;
	}
}


