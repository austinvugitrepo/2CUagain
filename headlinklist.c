#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct  Node *pos;
	int	val;

};


struct Node *hinsert(struct Node *, int);

/* Program written to practice inserting at head of linked list. */

int
main(void)
{
	struct Node *head = NULL;

	head = hinsert(head, 3);
	printf("%d\n", head->val);
		
	head = hinsert(head, 2);
	head = hinsert(head, 1);
	
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

struct Node *
hinsert(struct Node *ptr, int num)
{
	struct Node *h = malloc(sizeof(struct Node));
	h->val = num;
	h->pos = ptr;

	return h;

}
