#include <stdio.h>
#include <stdint.h>

#define circ_per(r) (2*3.14 * r) 
#define circ_area(r) (3.14 * r* r)

#define rec_per(a,b) (2*(a+b)/2.54) 
#define rec_area(a,b) (a * b / 2.54)

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
#define SWAP_UINT64(x)  ((((x) & 0xff00000000000000ull) >> 56) | (((x) & 0x00ff000000000000ull) >> 40) | (((x) & 0x0000ff0000000000ull) >> 24) | (((x) & 0x000000ff00000000ull) >> 8 ) | (((x) & 0x00000000ff000000ull) << 8 ) | (((x) & 0x0000000000ff0000ull) << 24) | (((x) & 0x000000000000ff00ull) << 40) | (((x) & 0x00000000000000ffull) << 56))

#define RGB888_TO_RGB565(r, g, b) ((r >> 3) | ((g >> 2) << 5) | ((b >> 3) << 11))

//#define RGB888_TO_RGB565(r, g, b) ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)

/*uint16_t = unsigned short 
uint32_t = unsigned int
uint64_t = typedef unsigned long long*/

int devision(int number) {
    for(int i = 1; i<501; i++) {
        if (i % number == 0) {
            printf("%d\n",i);

        }
    }
}
int factorial(int number) {
    int result = 1;
    for (int i = 1; i<number+1; i++) {
        result = result * i; 
    }
    return result;
}
int rgb() {

}
int main() {
    devision(100);//7
    printf("---------\n");
    printf("factorial of 10 - %d\n", factorial(10));//6
    printf("---------\n");
    printf("circule perimetr - %.6f\n", circ_per(4));//5
    printf("circule area - %.6f\n", circ_area(4));//5
    printf("---------\n");
    printf("rectangle perimetr - %.6f\n", rec_per(4,6));//4
    printf("rectangle area - %.6f\n", rec_area(4,6));//4
    printf("---------\n");
    printf("RGB888_TO_RGB565  rgb- 0x%x\n", RGB888_TO_RGB565(255, 100, 50));//3
    //printf("RGB888_TO_RGB565  r -0x%x, g - 0x%x, b - 0x%x\n", RGB888_TO_RGB565(255, 100, 50));//3
    printf("---------\n");
    unsigned short x = 35660;
    unsigned int y = 4294000295;
    unsigned long long z = 1800000000000001;
    printf("swap 16 %hu\n", SWAP_UINT16(x));//2
    printf("swap 32 %u\n", SWAP_UINT32(y));//2
    printf("swap 64 %llu\n", SWAP_UINT64(z));//2
}