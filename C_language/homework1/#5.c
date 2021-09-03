#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define circ_per(r) (2 * M_PI * r) 
#define circ_area(r) (M_PI * r * r)


int main() {
    
    printf("circle perimeter - %.6f\n", circ_per(6));//5
    printf("circle area - %.6f\n", circ_area(6));//5
}