#include "arraylibrary.h"



int main() {
    //array should be dynamically allocated 
    int* array = (int*)malloc(10*sizeof(int));//array of 10 int
    arr.len = 10;
    arr.array_pointer = array;

    for(int i=0; i<10;i++)
    {
        *(arr.array_pointer + i) = (i+1); 
    }
    
    //printf("%d", ar_find_first(arr.array_pointer,arr.len,5));

   printf("\nbefore adding:");
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
    ar_push(arr.array_pointer,arr.len,25);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
    ar_remove(arr.array_pointer,arr.len,5);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
    ar_push(arr.array_pointer,arr.len,250);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
    ar_remove(arr.array_pointer,arr.len,-1);
    for (int i=0; i<arr.len;i++)
    {
         printf("%d ", *(arr.array_pointer + i));
    }
   
    return 0;
}