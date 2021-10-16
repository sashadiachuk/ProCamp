#include <stdio.h>
#include <stdlib.h>
#include "mock.h"


char * strCopy(int MALLOC_FAILS,char* str) {

    int len = 0;
    if(str == NULL) {
        return 1;
    }
    if (str + '0' < 0xffff) {
        return 100;
    }
    for (int i =0; *(str+i)!= '\0'; i++)
    {
        len++;
    }
    char* newString = (char *)myMalloc(MALLOC_FAILS,(sizeof(char)*len)); 
	if (newString == NULL){
		return newString;
	}
    for (int i =0; i<len; i++) {
        *(newString+i) =  *(str+i);
    }
    return newString;
}



