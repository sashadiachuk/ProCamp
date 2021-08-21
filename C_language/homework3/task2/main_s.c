#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main() {

    initialize();
    push(10);
    push(20);
    push(30);
    push(40);
    printf("The top is %d\n",Top());
    pop();
    printf("The top after pop is %d\n",Top());
    display(top);
    return 0;
}