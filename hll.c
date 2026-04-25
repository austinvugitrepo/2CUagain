#include <stdio.h>
#include <stdlib.h>
#include <err.h>

struct Node {
	struct Node *pos;
	int val;

};

void headi(struct Node **, int);

/* more practice for inserting nodes at head position. */ 

int
main(void)
{
	struct Node *head = NULL;
	headi(&head, 3);

	printf("%d\n", head->val);

	headi(&head, 2);
	headi(&head, 1);

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

/* function for inserting nodes at head position. */ 

void headi(struct Node **ptr, int v)
{
	struct Node *n;

	if ((n = malloc(sizeof(struct Node))) == NULL)
		err(1, NULL);
	n->val = v;
	n->pos = *ptr;
	*ptr = n;
}
