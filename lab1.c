#include <stdio.h>
#include <math.h>

#define f(x) (pow(x, 2) - 4 * x - 10)
#define e 0.0001

void main(){
    float x1, x2, x0;

    // Input x1 and x2 until f(x1) and f(x2) have opposite signs
    do {
        printf("Enter the value of a and b \n");
        scanf("%f %f", &x1, &x2);
    } while (f(x1) * f(x2) > 0);
    
    // Bisection method
    do {
        x0 = (x1 + x2) / 2;
        if (f(x1) * f(x0) < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }
    } while (fabs(f(x0)) > e);

    printf("Root using Bisection Method is = %f\n", x0);
}

