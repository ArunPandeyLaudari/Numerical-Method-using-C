#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001  // Convergence criterion
#define f(x) (pow((x), 3) - 5 * (x) - 10)  // Function definition: f(x) = x^3 - 5x - 10

int main() {
    double x0, x1, x2;

    // Initial input and validation loop
    do {
        // Prompt user for initial guesses
        printf("Enter two  initial value x0 and x1: ");
        scanf("%lf %lf", &x0, &x1);

        // Check if the initial guesses are distinct
        if (fabs(x1 - x0) < EPSILON) {
            printf("Invalid input. x0 and x1 should be distinct.\n");
        }

    } while (fabs(x1 - x0) < EPSILON);  // Repeat if guesses are not distinct

    // Perform the Secant Method using a do-while loop
    do {
        // Calculate the next approximation using the Secant formula
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        // Update the previous two values
        x0 = x1;
        x1 = x2;

    } while (fabs(f(x2)) >= EPSILON);  // Continue until the function value is close enough to zero

    // Output the result
    printf("Root of the equation SM is: %.5lf\n", x2);

    return 0;
}

