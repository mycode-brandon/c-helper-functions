// File: charToBinary.c
// Author: Brandon Morgan
// Description: Converts a 'char' to a 'char[]' in binary format. Utilizes pointer parameter to take input array from caller scope.
// The function can cast an int to char and will generally preserve the last 8 bytes if the int is bigger than 255. e.g., 257 will return 0000 0001 (256 + 1 or 0000 0001 0000 0001)

#include <stdio.h>

#define SIZE_OF_ARRAY 8

void charToBinaryArray(char *array, char number) {
    // initialize all elements to '0' first
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        array[i] = '0';
    }
    
    // add '1's for each matching bit of the left-most bit and then shift to the left to check the next one
    for (int i = 0; number ; ++i) {
        if (number & 128) {
            array[i] = '1';
        }
        number <<= 1;
    }
}

int main() {
    char array[SIZE_OF_ARRAY];
    int number = 127;
    charToBinaryArray(array, number);
    
    printf("Binary of the number %d is ", number);
    for (int i = 0; i < SIZE_OF_ARRAY; ++i) {
        printf("%c", array[i]);
    }
    printf("\n");
    return 0;
}
