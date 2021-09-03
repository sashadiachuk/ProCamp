#include <stdio.h>
#include <stdint.h>

#define rec_per(a,b) (2 * (a + b) / 2.54) 
#define rec_area(a,b) (a * b / 2.54)

int main() {

    int a,b;
    printf("enter a value: ");
    scanf("%d",&a);
    printf("\nenter b value: ");
    scanf("%d",&b);
    printf("rectangle perimeter in inches - %.6f\n", rec_per(a,b));//4
    printf("rectangle area in inches - %.6f\n", rec_area(a,b));//4

}