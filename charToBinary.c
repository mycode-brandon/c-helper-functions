#include <stdio.h>

void *charToBinary(char *array, char number) {
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
    if (number < 129) charToBinary(array, number);
    
    printf("Binary of the number %d is ", number);
    for (int i = 0; i < (sizeof(array)/sizeof(array[i])); ++i) {
        printf("%c", array[i]);
    }
    printf("\n");
    return 0;
}
