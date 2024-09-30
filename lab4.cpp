#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001
#define f(x) (pow(x, 3) - 2 * x - 5)
#define df(x) (3*pow(x,2)-2)

int main() {
    double x0, x1;

    printf("Enter the initial value a: ");
    scanf("%lf", &x0);

    do {
        x1 = x0 - f(x0) / df(x0);
        x0 = x1;
    } while (fabs(f(x1)) >= EPSILON);

    printf("Root of equation using NRM is  %.5lf\n", x1);
    return 0;
}
