// Activity 2: Modify the above program and ask user to input N floating point numbers between 0.00 to 1.00 individually.
//  Determine in which interval the given number lies and calculate the chi value.

#include <stdio.h>
#include <math.h>

#define K 5  // Number of intervals
#define N 20 // Number of random numbers to input

int main()
{
    int freq[K] = {0}; // Frequency count for each interval
    double number, interval = 1.0 / K;
    double expected, chi_square = 0.0;

    // Step 1: Input N floating point numbers
    printf("Enter %d floating point numbers between 0.00 and 1.00:\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &number);

        // Input validation
        if (number < 0.0 || number >= 1.0)
        {
            printf("Invalid input. Number must be in [0.00, 1.00). Try again:\n");
            i--; // Decrement i to redo this iteration
            continue;
        }

        // Determine which interval the number belongs to
        int index = (int)(number * K);
        freq[index]++;
    }

    // Step 2: Calculate expected frequency
    expected = (double)N / K;

    // Step 3: Calculate Chi-Square statistic
    for (int i = 0; i < K; i++)
    {
        chi_square += pow(freq[i] - expected, 2) / expected;
    }

    // Step 4: Display the results
    printf("\nInterval\tObserved\tExpected\n");
    for (int i = 0; i < K; i++)
    {
        printf("[%.2f - %.2f)\t%d\t\t%.2f\n", i * interval, (i + 1) * interval, freq[i], expected);
    }

    printf("\nCalculated Chi-Square value: %.3f\n", chi_square);

       return 0;
}
