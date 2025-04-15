#include <stdio.h>

#define SIZE 2

// Function to multiply two 2x2 matrices
void multiply_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    int i, j, k;
    double temp[SIZE][SIZE] = {0};

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Copy temp into result
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            result[i][j] = temp[i][j];
}

// Function to multiply a 1x2 vector with a 2x2 matrix
void multiply_vector_matrix(double v[SIZE], double m[SIZE][SIZE], double result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += v[j] * m[j][i];
        }
    }
}

// Function to raise matrix to a power (e.g., T^n)
void matrix_power(double base[SIZE][SIZE], int power, double result[SIZE][SIZE]) {
    // Initialize result as identity matrix
    double temp[SIZE][SIZE] = {
        {1, 0},
        {0, 1}
    };

    for (int i = 0; i < power; i++) {
        multiply_matrix(temp, base, result);
        // Copy result to temp for next iteration
        for (int r = 0; r < SIZE; r++)
            for (int c = 0; c < SIZE; c++)
                temp[r][c] = result[r][c];
    }
}

int main() {
    double T[SIZE][SIZE] = {
        {0.9, 0.1},  // From Coke
        {0.2, 0.8}   // From Pepsi
    };

    double initial[SIZE];
    int steps;

    // Input initial population percentages
    printf("Enter initial population (Coke): ");
    scanf("%lf", &initial[0]);

    printf("Enter initial population (Pepsi) : ");
    scanf("%lf", &initial[1]);

    // Input number of steps
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    // Compute T^steps
    double Tn[SIZE][SIZE];
    matrix_power(T, steps, Tn);

    // Multiply initial vector by T^n
    double result[SIZE];
    multiply_vector_matrix(initial, Tn, result);

    // Print results
    printf("\nAfter %d steps:\n", steps);
    printf("Fraction drinking Coke: %.3f\n", result[0]);
    printf("Fraction drinking Pepsi: %.3f\n", result[1]);

    // Bonus: Lab questions
    // Q1: Pepsi → Coke in 2 steps (T^2[1][0])
    double T2[SIZE][SIZE], T3[SIZE][SIZE];
    matrix_power(T, 2, T2);
    matrix_power(T, 3, T3);
    printf("\nQ1: Pepsi → Coke in 2 steps: %.3f\n", T2[1][0]);
    printf("Q2: Coke → Pepsi in 3 steps: %.3f\n", T3[0][1]);

    return 0;
}
