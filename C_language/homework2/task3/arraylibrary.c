#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int ar_push(int* array,int length,int new)//add new element after the last one
{
  length = length + 1;
  if (arr.array_pointer[arr.len-1] != 0)
  {
  	int* new_arr = (int*)realloc(array,length*sizeof(int));
  	arr.array_pointer=new_arr;
  	arr.array_pointer[length-1] = new;
  	arr.len = length;
  }
  else 
  {
 	for (int i = 0; i <arr.len; i++)
 	{
 	   if(arr.array_pointer[i] == 0)
 	   {
 	   	arr.array_pointer[i] = new;
 	   	return 0;
 	   } 	   
 	}
  }
 }  
int ar_find_first(int* array,int length, int element){//returns the possitive index of the first occurrence of the given element in the array or -1 if the  number is not in the array 
     
     for(int i=0; i<length;i++)
     {
         if (array[i] == element)
         {
            return i;
         }
         else if(array[length-1] != element && i==length-1)
         {
            return -1;
     	 }
   
         
     }
    
}
void ar_remove(int index_for_remove) {//remove element by the index


	for (int i = 0; i < arr.len; i++)
	{
		if (index_for_remove == i)
		{
			int tmp;
			tmp = arr.array_pointer[arr.len - 1];
			arr.array_pointer[i] = arr.array_pointer[arr.len -1];
			arr.array_pointer[arr.len-1] = tmp;
			arr.len = arr.len - 1;
			printf("\nelement with index %d - removed\n",index_for_remove);
		}
	
	}
   }

