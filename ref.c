#include <stdio.h>

void addnum(int *, int *, int *);

/* practicing pass by reference but in C way. */

int
main(void)
{
	int num1 = 5;
	int num2 = 4;
	int sum;
	addnum(&num1, &num2, &sum);
	printf("The total is %d.\n", sum);

	return 0;

}

/* adding 2 numbers and updating 2nd number as the "total".
 * I would normally just return a sum value here but for
 * practice reasons I will be less orthodox.
 */ 
void
addnum(int *n1, int *n2, int *sum)
{
	*sum = *n1 + *n2;
}
