#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chunk {
	struct  chunk *pos;
	char	str[50];

};

  
/* This program uses a linked list to say hello world.
 * This was made to practice linked lists cuz i suck at them.
 */

int
main(void)
{
	struct chunk *fir = malloc(sizeof(struct chunk));
	struct chunk *sec = malloc(sizeof(struct chunk));
	
	/* can not assign directly to char array so use strcpy. */

	strcpy(fir->str, "Hello,");  
	strcpy(sec->str, "World!\n");  
				     	
	fir->pos = sec;
	sec->pos = NULL;

	struct chunk *cur = fir;

	while (cur != NULL) {
		printf("%s ", cur->str);
		cur = cur->pos;
	}
	cur = fir;
	struct chunk *tmp;

	while (cur != NULL) {
		tmp = cur->pos;
		free(cur);
		cur = tmp;
	}		  
		
	return 0;

}
