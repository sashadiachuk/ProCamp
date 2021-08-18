#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int* array_pointer;
    int len;
}array_info;

array_info  arr;
void ar_push(int* array,int length,int new)//add new element after the last one
{
  length = length + 1;
  int* new_arr = (int*)realloc(array,length*sizeof(int));
  arr.array_pointer=new_arr;
  arr.array_pointer[length-1] = new;
  arr.len = length;
 }
int ar_find_first(int* array,int length, int element){//returns the possitive index of the first occurrence of the given element in the array or -1 if the  number is not in the array 
     
     int occurrence =0;
     for(int i=0; i<length;i++)
     {
         if (*(array+i)==element)
         {
             occurrence = 1;
             return i;
             
         }
         
     }
     if (occurrence == 0)
     {
         return -1;
     }
   
}
void ar_remove(int* array,int length,int index_for_remove) {//remove element by the index
    int* new_array = (int*)malloc(sizeof(int)*(length-1));
    int index = 0;
    for(int i=0; i<length;i++){
        if(index_for_remove == i){
            printf("\nelement with index %d - removed\n", index_for_remove);
            index = 1;
        } 
        else {
            if (index == 0){
                *(new_array + i) = *(array+i);
               // printf("%d ", *(new_array + i));
                }
            else{
                *(new_array + i-1) = *(array+i);
               // printf("%d ", *(new_array + i-1));
                }
            }
        }
    arr.array_pointer = new_array;
    arr.len = length-1;
    }; 

