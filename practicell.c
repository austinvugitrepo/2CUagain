#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next; 
	int val;

};

int
main(void)
{
	struct Node *head = malloc(sizeof(struct Node));
	struct Node *first = malloc(sizeof(struct Node));
	struct Node *second = malloc(sizeof(struct Node));
	
	head->val = 1;
	first->val = 2;	
	second->val = 3;

	head->next = first;
	first->next = second;
	second->next = NULL; 

	struct Node *current = head;

	while(current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	
	putchar('\n');

	struct Node *tmp;
	current = head;

	while(current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}

	return 0;

}	
