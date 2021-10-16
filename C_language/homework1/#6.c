#include <stdio.h>
#include <stdint.h>

int factorial(int number) {
    int result = 1;
    for (int i = 1; i < number + 1; i++) {
        result = result * i; 
    }
    return result;
}

int main() {
    
    printf("---------\n");
    printf("factorial of 10 - %d\n", factorial(10));//6
    printf("---------\n");

}