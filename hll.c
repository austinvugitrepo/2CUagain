#include <stdio.h>
#include <stdlib.h>

struct Node *headi(struct Node *, int);

struct Node {
	struct Node *pos;
	int val;

};

/* more practice for inserting nodes at head position */ 

int
main(void)
{
	struct Node *head = NULL;
	head = headi(head, 3);

	printf("%d\n", head->val);

	head = headi(head, 2);
	head = headi(head, 1);

	struct Node *cur = head;
	while (cur != NULL) {
		printf("%d ", cur->val);
		cur = cur->pos;
	}

	putchar('\n');

	struct Node *tmp;
	cur = head;

	while (cur != NULL) {
		tmp = cur->pos;
		free(cur);
		cur = tmp;
	}

	return 0;

}

/* function for inserting nodes at head position */ 

struct Node *headi(struct Node *ptr, int v)
{
	struct Node *hptr = malloc(sizeof(struct Node));
	hptr->val = v;
	hptr->pos = ptr;

	return hptr;

}
