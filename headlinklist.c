#include <stdio.h>
#include <stdlib.h>
#include <err.h>

struct Node {
	struct Node *pos;
	int val;
};


void hinsert(struct Node **, int);

/* Program written to practice inserting at head of linked list. */

int
main(void)
{
	struct Node *head = NULL;

	hinsert(&head, 3);
	printf("%d\n", head->val);
		
	hinsert(&head, 2);
	hinsert(&head, 1);
	
	struct Node *cur = head;

	while (cur != NULL) {
		printf("%d ", cur->val);
		cur = cur->pos;
	}
	
	putchar('\n');

	struct Node *tmpos;
	cur = head;

	while (cur != NULL) {
		tmpos = cur->pos;
		free(cur);
		cur = tmpos;
	}

	return 0;
}

/* This function helps faciliates inserting at head. */

void
hinsert(struct Node **ptr, int num)
{
	struct Node *h;
	if ((h = malloc(sizeof(struct Node))) == NULL)
		err(1, NULL);
	h->val = num;
	h->pos = *ptr;
	*ptr = h;
}
