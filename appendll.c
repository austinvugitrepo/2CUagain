#include <stdio.h>
#include <stdlib.h>
#include <err.h>

struct Node {
	struct Node *pos;
	int val;
};

void appendNode(struct Node **, int);

/* Today I will be practicing appending nodes in link list. */

int
main(void)
{
	struct Node *head = NULL;
	appendNode(&head, 1);
	printf("%d", head->val);
	putchar('\n');

	return 0;

}

void
appendNode(struct Node **ptr, int v)
{
	struct Node *n;

	if ((n = malloc(sizeof(struct Node))) == NULL)
		err(1, NULL);
	
	n->val = v;
	n->pos = NULL;

	/* if list is empty: */

	if (*ptr == NULL) {
		*ptr = n;
		return;
	}
}
