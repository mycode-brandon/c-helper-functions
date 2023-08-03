void charToBinary(char *binary_char_array, char number) {
    int size = sizeof(binary_char_array) / sizeof(binary_char_array[0]);
    
    for (int i = 0; i < size; ++i) {
        binary_char_array[i] = '0';
    }
    
    printf("Decimal: %d\n", number);
    printf("Hexadecimal: %x\n", number);
    printf("Bindary: ");
    for (int i = 0; number ;++i) {
        if (number & 128) {
            binary_char_array[i] = '1';
        }
        number <<= 1;
    }
}
