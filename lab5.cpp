#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n], value, result = 0.0;

    // Input the data points
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Input the interpolation point
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    // Lagrange interpolation calculation
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    // Output the result
    printf("Interpolated value at %.2f is %.2f\n", value, result);

    return 0;
}

