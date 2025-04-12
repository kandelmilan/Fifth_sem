// Activity 4: Using the multiplicative congruential method, find the period of the generator for a = 13, m =
// 64, and XO = 1, 2, 3, and 4

#include <stdio.h>

#define MAX_M 1000
#define MAX_SEEDS 4
#define MAX_STEPS 100

int generate_sequence(int seed, int a, int m, int output[]) {
    int visited[MAX_M] = {0};
    int x = seed;
    int count = 0;

    while (!visited[x] && count < MAX_STEPS) {
        output[count++] = x;
        visited[x] = 1;
        x = (a * x) % m;
    }

    return count; // returns period
}

int main() {
    int a = 13, m = 64;
    int seeds[MAX_SEEDS] = {1, 2, 3, 4};
    int sequences[MAX_SEEDS][MAX_STEPS];
    int periods[MAX_SEEDS];
    int max_steps = 0;

    printf("Multiplicative Congruential Method\n");
    printf("a = %d, m = %d\n\n", a, m);

    // Generate all sequences
    for (int i = 0; i < MAX_SEEDS; i++) {
        periods[i] = generate_sequence(seeds[i], a, m, sequences[i]);
        if (periods[i] > max_steps)
            max_steps = periods[i];
    }

    // Print header
    printf("i\t");
    for (int i = 0; i < MAX_SEEDS; i++) {
        printf("X0=%-4d\t", seeds[i]);
    }
    printf("\n---------------------------------------------------------\n");

    // Print values step-by-step
    for (int i = 0; i <= max_steps; i++) {
        printf("%-2d\t", i);
        for (int j = 0; j < MAX_SEEDS; j++) {
            if (i < periods[j])
                printf("%-7d\t", sequences[j][i]);
            else
                printf(" \t");
        }
        printf("\n");
    }

    // Print periods
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < MAX_SEEDS; i++) {
        printf("Period for X0=%d = %d\n", seeds[i], periods[i]);
    }

    // Minimum period
    int min = periods[0];
    for (int i = 1; i < MAX_SEEDS; i++) {
        if (periods[i] < min)
            min = periods[i];
    }

    printf("\nMinimum Period among all seeds = %d\n", min);
    return 0;
}
