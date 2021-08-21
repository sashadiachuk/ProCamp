#include <stdio.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))


int square (int item)
{
    item = item * item;
    return item;
}


void map (int* array, int len,int (*p)(int) ){

    for(int i = 0; i < len; i++) {

         *(array+i) = p(*(array+i));
     }             
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    for(int i =0; i< ARRAY_SIZE(arr); i++)
    {
        printf("%d ",arr[i]);
    }
    map(arr, ARRAY_SIZE(arr), square);
    printf("\n ");
    for(int i =0; i< ARRAY_SIZE(arr); i++)
    {
        printf("%d ",arr[i]);
    }

}