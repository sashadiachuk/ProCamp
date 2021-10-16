#include <stdio.h>
#include <stdlib.h>
char* result;

void* myMalloc(int MALLOC_FAILS,size_t size) {

  if (MALLOC_FAILS == 1)
      return NULL;
  
  return malloc(size);

 }
 /*A mock is a simulated function or module that mimics the behavior of a real implementation but is fully controlled by the unit test itself.

 In the following example, we create a mock 
 for myMalloc which should be called by strCopy so that we can
 validate that strCopy behaves correctly if malloc fails and succeeds.*/

char* setResultChar(char* arg) {
    
    return result = arg;

}

int  setResultInt(int arg) {

    return result = arg;

}