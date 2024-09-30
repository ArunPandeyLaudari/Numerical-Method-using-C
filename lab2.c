#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001  // Convergence criterion
#define f(x) (pow((x), 3) - 4 * (x) - 10)  // Function definition: f(x) = x^3 - 4x - 10

int main() {
    double a, b, c;

    // Prompt user for input
    printf("Enter the values for interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    // Validate initial guesses to ensure they have opposite signs
    while (f(a) * f(b) >= 0) {
        printf("Invalid interval.\n");
        printf("Please enter the values for interval [a, b] again: ");
        scanf("%lf %lf", &a, &b);
    }

    // Perform the False Position method using a do-while loop
    do {
        // Calculate the point of intersection using the False Position formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Check for convergence
        if (fabs(f(c)) < EPSILON) {
            break;
        }

        // Update the interval based on the sign of f(c)
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

    } while (fabs(b - a) >= EPSILON);  // Continue until the desired accuracy is achieved

    // Output the result
    printf("Root of the equation using FPM is: %.5lf\n", c);

    return 0;
}

