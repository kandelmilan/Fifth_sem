// Lab 3: Uniformity Testing of random Numbers using Chi- Square Test
// Activity 1:, Write a program to test either the given random numbers are uniformly distributed or not.
#include <stdio.h>
#include <math.h>

#define K 5  // Number of intervals (You can change this)
#define N 100 // Number of provided numbers

int main() {
    // Declare the frequency array and observed frequencies
    int freq[K] = {0};  // Frequency array to store counts in each interval
    float observed[K]; // Array to store observed frequencies entered by the user
    float interval = 1.0 / K;
    float expected, chi_square = 0.0;

    // Step 1: Take observed frequencies input from the user
    printf("Enter the observed frequencies for each of the %d intervals:\n", K);
    for (int i = 0; i < K; i++) {
        printf("Observed frequency for interval [%0.2f - %0.2f): ", i * interval, (i + 1) * interval);
        scanf("%f", &observed[i]);
    }

    // Step 2: Calculate expected frequency
    expected = (float)N / K;  // Expected frequency for each interval

    // Step 3: Calculate Chi-Square statistic
    for (int i = 0; i < K; i++) {
        chi_square += pow(observed[i] - expected, 2) / expected;
    }

    // Step 4: Display the results
    printf("\nInterval\tObserved\tExpected\n");
    for (int i = 0; i < K; i++) {
        printf("[%.2f - %.2f)\t%.2f\t\t%.2f\n", i * interval, (i + 1) * interval, observed[i], expected);
    }

    printf("\nCalculated Chi-Square value: %.3f\n", chi_square);

    // Hypothesis Test
    // Critical value for Chi-Square at alpha=0.05 and df=K-1 (K=5, df=4) is 9.488 (this value comes from a Chi-Square table)
    float critical_value = 9.488;
    printf("\nCritical Chi-Square value (df = %d, alpha = 0.05): %.3f\n", K-1, critical_value);

    if (chi_square > critical_value) {
    printf("Accept H1: The numbers are not uniformly distributed.\n");
    } else {
        printf("Accept H0: The numbers are uniformly distributed.\n");
    }

    return 0;
}
