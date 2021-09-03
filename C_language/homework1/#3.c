#include <stdio.h>
#include <stdint.h>


int main() {

    uint16_t Rgb565 = 0;
    int Rgb888 = 259122;
    Rgb565 = (((Rgb888&0xF80000)>>8) + ((Rgb888&0xFC00)>>5) + ((Rgb888&0xF8)>>3));

    printf("%d", Rgb565);
}