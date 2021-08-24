#include <stdio.h>
#include <stdlib.h>

char * strCopy(char* str) {

    int len = 0;
	if (str == NULL) {
		return NULL;
	}
	
	for (int i =0; *(str+i)!= '\0'; i++)
    {
        len++;
    }
    char* newString = (char*)malloc(sizeof(char)*len);
    for (int i =0; i<len; i++) {
        *(newString+i) =  *(str+i);
    }
    return newString;
}

int main () {

    char string[] = "Hello";
    printf( "%s",strCopy(string));
}

