/* I am practicing more KNF C again, this time with linked lists. */

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{ 	 
	struct node {
		struct  node *next; /* struct position ptr for linked list. */
		int	number;
	};
	
	/* making node pointers to point to node structs created.
	 * I can treat the pointers as representatives to structs.
	 * Like dynamic arrays kinda.
	 */   

	struct node *head = malloc(sizeof(struct node));
	struct node *two = malloc(sizeof(struct node));
	struct node *three = malloc(sizeof(struct node));

	/* assigning my nodes my values.
	 * -> means like dereferencing for struct members.
	 */ 

	head->number = 1; 
	two->number = 2; 
	three->number = 3; 

	/* Time to chain my link. */

	head->next = two; /* assigning address of two to head. */
	two->next = three;
	three->next = NULL; /* end of link. */

	/* traversing my link. */

	struct node *current = head; /* pointer to address of first node. */

	while (current != NULL) {
		printf("%d\n", current->number);
		current = current->next;
	}

	/* free memory after done. */

	current = head; /* reset ptr to beginning of link. */
	struct node *tmpnext;

	while (current != NULL) {
		tmpnext = current->next;
		free(current);
		current = tmpnext; /* set current to next position. */
	}

	return 0;

}
