#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // Number of random numbers

// Selection Sort for float array
void selectionSort(float arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap
        float temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    float rand_nums[N];
    float d_plus = 0.0, d_minus = 0.0, D, D_critical;

    // Input random numbers
    printf("Enter %d random numbers between 0 and 1:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%f", &rand_nums[i]);

        if (rand_nums[i] < 0 || rand_nums[i] > 1)
        {
            printf("Error: Number must be between 0 and 1.\n");
            return 1;
        }
    }

    // Input critical value
    printf("\nEnter the tabulated (critical) value for D: ");
    scanf("%f", &D_critical);

    // Sort the random numbers
    selectionSort(rand_nums, N);

    // Display sorted numbers
    printf("\nSorted numbers:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%.4f ", rand_nums[i]);
    }
    printf("\n");

    // Print table header
    printf("\n%-4s %-10s %-10s %-10s %-10s\n", "i", "R(i)", "i/n", "D+", "D-");
    printf("------------------------------------------------------\n");

    // Calculate D+ and D-, print table
    for (int i = 0; i < N; i++)
    {
        float Fi = (float)(i + 1) / N;
        float Fi_minus = (float)i / N;
        float Dp = Fi - rand_nums[i];
        float Dm = rand_nums[i] - Fi_minus;

        if (Dp > d_plus) d_plus = Dp;
        if (Dm > d_minus) d_minus = Dm;

        printf("%-4d %-10.4f %-10.4f %-10.4f %-10.4f\n", i + 1, rand_nums[i], Fi, Dp, Dm);
    }

    // Calculate KS statistic
    D = (d_plus > d_minus) ? d_plus : d_minus;

    // Display results
    printf("\nD+ = %.4f\n", d_plus);
    printf("D- = %.4f\n", d_minus);
    printf("KS Statistic D = %.4f\n", D);
    printf("Tabulated Critical Value = %.4f\n", D_critical);

    if (D < D_critical)
        printf("Result: Uniformity Test Passed\n");
    else
        printf("Result: Uniformity Test Failed\n");

    return 0;
}
