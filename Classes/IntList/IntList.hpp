#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
	private:
		struct _list {
			int value;
			struct _list *next;
		};
		typedef struct _list List;

		List *_front;
		List *_back;
		size_t _size;

		void reccopy(const List *ptr);

	public:
		IntList();
		IntList(const IntList &list);
		~IntList();

		size_t size() const;

		void push_front(int value);
		void push_back(int value);

		void pop_front();
		void pop_back();

		bool empty();
};

#endif // INT_LIST_HPP
