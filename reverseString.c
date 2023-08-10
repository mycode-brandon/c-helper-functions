// File: reverseString.c
// Author: Brandon Morgan
// Description: Simple function that revereses a string

#include <stdio.h>

void reverse_string(char *string_array, int size_of_array) {
    char temporary_var;
    for (int i = 0, j = size_of_array -1; i < j; ++i, --j) {
        printf("i: %d, j: %d \n", i, j);
        temporary_var = string_array[i];
        string_array[i] = string_array[j];
        string_array[j] = temporary_var; 
        printf("string_array[i]: %c, string_array[j]: %c \n", string_array[i], string_array[j]);
    }
}

int main() {
    char string_array[] = {'h', 'e', 'l', 'l', 'o', '!'};
    printf("word to reverse: %s \n", string_array);
    reverse_string(string_array, 6);
    printf("reversed word: %s\n", string_array);

    return 0;
}
