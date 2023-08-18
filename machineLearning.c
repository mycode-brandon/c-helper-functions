#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAIN_COUNT (sizeof(train)/sizeof(train[0]))

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
    {5,10},
};


float rand_float(void) {
    return (float) rand() / (float) RAND_MAX;
}


float cost(float w) {
    float result = 0.0f;
    
    for (size_t i = 0; i < TRAIN_COUNT; i++) {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
        //printf("actual: %f, expected: %f\n", y, train[i][1]);
    }
    result /= TRAIN_COUNT;
    return result;
}


int main() {
    //printf("%lld", TRAIN_COUNT);
    srand(69);
    // y = x*w;
    float w = rand_float() * 10.0f;
    float result = cost(w);
    printf("%f\n", result);


    return 0;
}