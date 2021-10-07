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
		new_node->next = nullptr;
		_back = new_node;
	}
	_front = new_node;
	_size += 1;
}

void IntList::push_back(int value) {
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

void IntList::pop_front() {
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

void IntList::pop_back() {
	if (empty()) {
		return;
	}
	List *node_to_delete = _front;
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

bool IntList::empty() {
	return ( (_front == nullptr) && (_back == nullptr) );
}

