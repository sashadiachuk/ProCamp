#include <stdio.h>
#include <stdint.h>

int division(int number) {
    for(int i = 1; i < 501; i++) {
        if (number % i == 0) {
            printf("%d\n",i);

        }
    }
}


int main () {

    int input = 0;
    printf("enter the number: ");
    scanf("%d", &input);

    devision(input);
}