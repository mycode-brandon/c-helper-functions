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


int main() {
    srand(69);
    // y = x*w;
    float w = rand_float() * 1000.0f;

    for (int i = 0; 9 < TRAIN_COUNT; i++) {
        float x = train[i][0];
        float y = x*w;
        printf("actual: %f, expected: %f\n", y, train[i][0]*2);
    }

    return 0;
}