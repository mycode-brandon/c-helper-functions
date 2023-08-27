#include <stdio.h>
#include <math.h>

double Cosine(double x) {
    double t0 = 1;
    double t1, R, sum  = t0;

    for (int i = 0; fabs(t1/sum) > 0.00000001; i++) {
        R = -x*x/(2*i*(2*i-1));
        t1 = R * t0;
        sum = sum + t1;
        t0 = t1;
    }

    return sum;
}


int main() {

    printf("%f\n", Cosine(1.5));
    return 0;
}