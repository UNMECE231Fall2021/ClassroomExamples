#include <stdio.h>

struct _list {
	int value;
	struct _list *next;
};
typedef struct _list List;

void print_list(List *x) {
	List *temp;
	for (temp = x; temp != NULL; temp = temp->next) {
		printf("%d ", temp->value);
	}
	printf("\n");
}

void add_node(List *n, List *n_new) {
	if (n == NULL) {
		return;
	}
	n_new->next = n->next;
	n->next = n_new;
}

void rm_node_after(List *n) {
	if (n->next == NULL) {
		return;
	}
	n->next = n->next->next;
}


int main() {
	List l3 = {3, NULL};
	List l2 = {2, &l3};
	List l1 = {1, &l2};

	List *temp;
	temp = &l3;
	printf("%d, %p\n", temp->value, temp->next);

	print_list(&l1);

	List l5 = {5, NULL};
	List l4 = {4, NULL};

	// Adding l4 after l3
	add_node(&l3, &l4);
	// Expect: 1 2 3 4
	print_list(&l1);

	// Adding l5 after l2
	add_node(&l2, &l5);
	// Expect: 1 2 5 3 4
	print_list(&l1);

	// Remove after l1 (so we remove l2)
	rm_node_after(&l1);
	// Expect: 1 5 3 4
	print_list(&l1);

	return 0;
}
