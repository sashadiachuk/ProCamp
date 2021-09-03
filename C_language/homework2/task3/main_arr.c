#include "arraylibrary.h"

#include <stdio.h>

int main() {
    //array should be dynamically allocated 
    int* array = (int*)calloc(100,sizeof(int));//array of 10 int
    if (array != NULL)
    {
    	arr.len = 100;
    	arr.array_pointer = array;

    	for(int i=0; i<99;i++)
    	{
        	*(arr.array_pointer + i) = (i+1); 
    	}
    
    	printf("tut %d", ar_find_first(arr.array_pointer,arr.len,5));

    }
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
    ar_push(arr.array_pointer,arr.len,25);

    printf("\nafter adding:");

    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
  
    ar_remove(5);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
  /*  ar_push(arr.array_pointer,arr.len,250);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
    ar_remove(arr.array_pointer,arr.len,-1);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
   */
    return 0;
}
