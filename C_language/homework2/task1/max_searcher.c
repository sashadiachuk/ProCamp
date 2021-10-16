#include <stdio.h>
#include <stdlib.h>

int* search_max_item(int* array, int len) {
    
    int* max =array;
    for (int i=1; i<len;i++){
        if (*max<*(array+i)) {
            max = array+i;
        }
    }  

    return max;

}


int main () {

    int array[10] = {0,3,1,4,5,11,2499,22,0,9};
    int len =0;
    printf("%d",*(search_max_item(array, 10)));
}