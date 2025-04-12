#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define SEED 35791246
#define PI 3.14159

int main() {
    int N[100];  // Array to store the number of iterations for each trial
    double x, y;
    int i, n = 0, r = 0, p;
    double z;
    double pi, error;
    char ch;

    // Ask the user how many iterations they want to perform
    do {
        printf("Enter the number of iterations used to estimate pi: ");
        scanf("%d", &N[r]);
        printf("\nEnter 'y' to continue with next iteration or 'n' to stop: ");
        getchar();  // To consume the newline character from the previous input
        scanf("%c", &ch);
        
        if (ch == 'y' || ch == 'Y') {
            r++;
        }
    } while (ch == 'y' || ch == 'Y');

    // Print the table header
    printf("| No. of iterations\t| Estimate of pi\t| Percent of error\t|\n");

    // Loop through each trial and calculate the estimate for pi and the error
    for (p = 0; p <= r; p++) {
        srand(SEED);  // Set random seed
        n = 0;  // Reset the count for each trial

        // Perform the Monte Carlo simulation for the given number of iterations
        for (i = 0; i < N[p]; i++) {
            x = (double) rand() / RAND_MAX;  // Generate a random x coordinate between 0 and 1
            y = (double) rand() / RAND_MAX;  // Generate a random y coordinate between 0 and 1
            z = x * x + y * y;  // Calculate the square of the distance from the origin

            if (z <= 1) {
                n++;  // If the point is inside the unit circle, increment the count
            }
        }

        // Estimate pi and calculate the percentage error
        pi = (double) n / N[p] * 4;  // Estimate pi using the Monte Carlo method
        error = fabs((PI - pi) / PI) * 100;  // Calculate the percentage error

        // Print the results in a table format
        printf("| %d\t\t\t| %.6f\t\t| %.3f\t\t\t|\n", N[p], pi, error);
    }

    return 0;
}
