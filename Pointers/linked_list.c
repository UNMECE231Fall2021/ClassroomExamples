#include <stdio.h>

struct _list {
	int value;
	struct _list *next;
};
typedef struct _list List;

int main() {
	List l3 = {3, NULL};
	List l2 = {2, &l3};
	List l1 = {1, &l2};

	List *temp;
	//printf("%d, %p\n" (*temp).value, (*temp).next);
	temp = &l3;
	printf("%d, %p\n", temp->value, temp->next);

	for (temp = &l1; temp != NULL; temp = temp->next) {
		printf("%d ", temp->value);
	}
	printf("\n");

	return 0;
}
