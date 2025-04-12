// Activity 3: Apply all LCM (Additive, Mixed or Multiplicative) based on the input values of a and c (determine the type of and generate the random numbers based on that).
// In this case you can provide a choice to user which method they want to choose. Based on the choice you should apply the respective formulas.

#include <stdio.h>

int main()
{
    int num_digits, num_randoms;
    int R, a, c, m;
    int initial_seed;

    // Inputs
    printf("Enter number of digits for each random number and how many random numbers to generate: ");
    scanf("%d\n%d", &num_digits, &num_randoms);

    printf("Enter initial seed value (R0) and multiplier constant (a): ");
    scanf("%d\n%d", &R, &a);

    initial_seed = R;

    printf("Enter increment constant (c) and the value of m: ");
    scanf("%d\n%d", &c, &m);

    // Determine the type of LCM
    printf("\nLCM Type: ");
    if (a == 1 && c != 0)
        printf("Additive\n");
    else if (c == 0)
        printf("Multiplicative\n");
    else
        printf("Mixed\n");

    // Header
    printf("\nRandom Numbers Generated Using LCM:\n");
    printf("-----------------------------------------------------\n");
    printf("SN\tR(i)\t\tRandom Number (0 to m-1)\n");
    printf("-----------------------------------------------------\n");

    // Generate random numbers based on the LCM type
    for (int i = 0; i < num_randoms; i++)
    {
        printf("%d\t%d\t\t%d\n", i, R, R);

        // For Additive LCM: R(i+1) = (R(i) + c) % m
        if (a == 1 && c != 0)
        {
            R = (R + c) % m; // Additive case
        }
        // For Multiplicative LCM: R(i+1) = (a * R(i)) % m
        else if (c == 0)
        {
            R = (a * R) % m; // Multiplicative case
        }
        // For Mixed LCM: R(i+1) = (a * R(i) + c) % m
        else
        {
            R = (a * R + c) % m; // Mixed case
        }
    }

    return 0;
}
