/*
 * Converts a 'char' to a 'char[]' in binary format. Utilizes pointer parameter to take input array from caller scope.
 * The function can cast an int to char and will generally preserve the last 8 bytes if the int is bigger than 255. e.g., 257 will return 0000 0001 (256 + 1 or 0000 0001 0000 0001)
 */

#include <stdio.h>

void charToBinary(char *array, char number) {
    int size_of_array;
    size_of_array = sizeof(array)/sizeof(array[0]);
    
    // initialize all elements to '0' first
    for (int i = 0; i < size_of_array; ++i) {
        array[i] = '0';
    }
    
    for (int i = 0; number ; ++i) {
        if (number & 128) {
            array[i] = '1';
        }
        number <<= 1;
    }
}

int main() {
    char array[8];
    int number = 127;
    charToBinary(array, number);
    
    printf("Binary of the number %d is ", number);
    for (int i = 0; i < (sizeof(array)/sizeof(array[i])); ++i) {
        printf("%c", array[i]);
    }
    printf("\n");
    return 0;
}
