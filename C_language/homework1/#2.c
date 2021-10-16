#include <stdio.h>
#include <stdint.h>

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
#define SWAP_UINT64(x)  ((((x) & 0xff00000000000000ull) >> 56) | (((x) & 0x00ff000000000000ull) >> 40) | (((x) & 0x0000ff0000000000ull) >> 24) | (((x) & 0x000000ff00000000ull) >> 8 ) | (((x) & 0x00000000ff000000ull) << 8 ) | (((x) & 0x0000000000ff0000ull) << 24) | (((x) & 0x000000000000ff00ull) << 40) | (((x) & 0x00000000000000ffull) << 56))


int main() {

    unsigned short x = 35660;
    unsigned int y = 4294000295;
    unsigned long long z = 1800000000000001;
    printf("swap 16 %hu\n", SWAP_UINT16(x));
    printf("swap 32 %u\n", SWAP_UINT32(y));
    printf("swap 64 %llu\n", SWAP_UINT64(z));
}
