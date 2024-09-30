#include <stdio.h>

int main() {
    int n;
   
    // Input: Number of points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];  // x stores the x-values, y stores divided differences

    // Input the x and y values (initial y values are in the first column of y)
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Create divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Input the value to interpolate
    float value;
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    // Use Newton's formula to calculate the result
    float result = y[0][0];  // First term
    float product;
   
    for (int i = 1; i < n; i++) {
        product = 1;
        for (int j = 0; j < i; j++) {
            product *= (value - x[j]);
        }
        result += product * y[0][i];
    }

    // Output the interpolated value
    printf("Interpolated value at %.2f is %.2f\n", value, result);

    return 0;
}


