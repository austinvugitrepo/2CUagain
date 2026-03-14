#include <stdio.h>
#include <stdlib.h>

int main(){
	
int size = 0;
printf("What is the size of the array?: ");
scanf("%d", &size);
// "%d" represents integer
printf("The array can hold %d elements\n", size);
//type casting so I can maintain portability even with C++ compiler
int* arr = (int*)malloc(size * sizeof(int));
printf("Enter the elements in the array: ");
for(int i = 0; i < size; i++){
scanf("%d", &arr[i]);  
}
printf("Your array: ");
for(int i = 0; i < size; i++){
printf("%d", arr[i]);
}
printf("\n");
free(arr);
return 0;
}
