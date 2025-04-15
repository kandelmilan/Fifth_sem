// Activity 3: Generate the N random numbers using Linear Congruential Method and test the uniformity of generated numbers using Chi-Square method.
//  Before doing calculation of chi be sure that your generator has generated minimum 40 numbers.

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For qsort

#define N 50 // Number of random numbers (must be >= 40)
#define K 5  // Number of intervals

// LCG parameters (example values)
#define A 1664525
#define C 1013904223
#define M 4294967296 // 2^32

unsigned int seed = 12345; // You can change the seed for different results

// Linear Congruential Generator
float generate_random()
{
    seed = (A * seed + C) % M;
    return (float)seed / M;
}

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    float fa = *(float *)a;
    float fb = *(float *)b;
    return (fa > fb) - (fa < fb);
}

int main()
{
    float numbers[N];
    int freq[K] = {0};
    float interval = 1.0 / K;
    float expected = (float)N / K;
    float chi_square = 0.0;

    // Step 1: Generate N random numbers
    for (int i = 0; i < N; i++)
    {
        numbers[i] = generate_random();
    }

    // Step 2: Sort the numbers
    qsort(numbers, N, sizeof(float), compare);

    // Step 3: Print the sorted random numbers
    printf("Generated Random Numbers (Sorted):\n");
    for (int i = 0; i < N; i++)
    {
        printf("%.4f ", numbers[i]);
    }
    printf("\n\n");

    // Step 4: Count observed frequencies
    for (int i = 0; i < N; i++)
    {
        int index = (int)(numbers[i] / interval);
        if (index == K)
            index = K - 1; // Handle edge case where number == 1.0
        freq[index]++;
    }

    // Step 5: Chi-Square Table Output
    printf("Chi-Square Table:\n");
    printf("Interval\tOi\tEi\tOi-Ei\t(Oi-Ei)^2\t(Oi-Ei)^2/Ei\n");

    for (int i = 0; i < K; i++)
    {
        float diff = freq[i] - expected;
        float diff_sq = diff * diff;
        float term = diff_sq / expected;
        chi_square += term;

        printf("%d\t\t%d\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
               i + 1, freq[i], expected, diff, diff_sq, term);
    }

    printf("\nTotal Chi-Square value: %.3f\n", chi_square);
    return 0;
}
    