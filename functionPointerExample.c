// Example use of function pointers

#include <stdio.h>

float add(float x, float y) {
    return x + y;
}
float subtract(float x, float y) {
    return x - y;
}
float multiply(float x, float y) {
    return x * y;
}
float divide(float x, float y) {
    return x / y;
}

float (*select_operation())(float, float) {
    int operation_selection = 0;
    printf("Select an operation: \n");
    printf("1. Add \n");
    printf("2. Subtract \n");
    printf("3. Multiply \n");
    printf("4. Divide \n");
    printf("Enter Selection: ");
    scanf("%d", &operation_selection);
    
    switch(operation_selection) {
        case 1: return add;
        case 2: return subtract;
        case 3: return multiply;
        case 4: return divide;
        default: return add;
    }
}

int main() {
    
    float (*operation)(float, float) = select_operation();
    printf("Result of x=20 and y=5: %0.2f \n", operation(20,5));
    
    float (*operation_array[])(float, float) = {add, subtract, multiply, divide};
    float product = (*operation_array[2])(20, 5);
    printf("\nUsing an array of function pointers instead:\n");
    printf("operation_array[0]: %0.2f\n", (*operation_array[0])(20, 5));
    printf("operation_array[1]: %0.2f\n", (*operation_array[1])(20, 5));
    printf("operation_array[2]: %0.2f\n", (*operation_array[2])(20, 5));
    printf("operation_array[3]: %0.2f\n", (*operation_array[3])(20, 5));
    
    printf("\nComplete!\n");
    return 0;
}
