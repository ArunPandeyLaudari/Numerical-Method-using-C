#include <stdio.h>

int main() {
    int n;
   
    // Input: Number of points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];  // x stores x-values, y stores forward differences

    // Input the x and y values
    printf("Enter the x values (assume they are equally spaced):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Create forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Input the value to interpolate
    float value;
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    // Apply Newton's forward difference formula
    float result = y[0][0];
    float h = x[1] - x[0];
    float term = 1;
    int k = (int)((value - x[0]) / h);

    for (int i = 1; i < n; i++) {
        term *= (value - x[0] - (i - 1) * h) / (i * h);
        result += term * y[0][i];
    }

    // Output the result
    printf("Interpolated value at %.2f is %.2f\n", value, result);

    return 0;
}

 
