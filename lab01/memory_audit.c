#include <stdio.h>

int main(void) {
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of short: %zu bytes\n", sizeof(short));

   unsigned char byte_test = 255;
    printf("Size of unsigned char: %zu bytes\n", sizeof(unsigned char));

    byte_test = byte_test + 1;
    printf("After overflow (+1): dec = %u, hex = 0x%02X\n", byte_test, byte_test);
    return 0;
}
