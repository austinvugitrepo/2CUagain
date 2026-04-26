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
	appendNode(&head, 2);
	appendNode(&head, 3);
	
	struct Node *cur;
	cur = head;

	while (cur != NULL) {
		printf("%d ",cur->val);
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

/* This function appends nodes to the end. */
 
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
	
	struct Node *cur;
	cur = *ptr;
	/* travel to last node pointing to NULL and not be at NULL. */
	while (cur->pos != NULL)
		cur = cur->pos;
	cur->pos = n; 
}
