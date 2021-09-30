#ifndef _INTLIST_HPP
#define _INTLIST_HPP

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
};

#endif // _INTLIST_HPP
