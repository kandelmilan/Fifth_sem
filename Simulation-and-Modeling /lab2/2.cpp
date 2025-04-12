// Activity 2: Finding Cycle Length Modify the above program (activity 1) and find the cycle length. once you identify there is present of same random number as given in seed, you have to terminate your program.
// e.g. In activity 1 if you try to generate 20 random numbers, the numbers repeats after 15 unique numbers(2,21,6,26,20,28,7,4,8,13,27,29,16,23,24,2...). In this case your program should stop generating
// random number

#include <stdio.h>

int main()
{
    int num_digits;
    int R, a, c, m;
    int initial_seed;
    int count = 0;

    printf("Enter number of digits for each random number and initial seed value (R0): ");
    scanf("%d\n%d", &num_digits,&R);

    // printf("Enter initial seed value (R0): ");
    // scanf("%d", &R);
    initial_seed = R;  

    printf("Enter multiplier constant (a): ");
    scanf("%d", &a);

    printf("Enter increment constant (c): ");
    scanf("%d", &c);

    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("\nRandom Numbers Generated Using LCM (Cycle detection):\n");
    printf("-----------------------------------------------------\n");
    printf("SN\tR(i)\t\tRandom Number (0 to m-1)\n");
    printf("-----------------------------------------------------\n");

    printf("%d\t%d\t\t%d\n", count, R, R); // Print R0
    count++;

    while (1)
    {
        R = (a * R + c) % m;

        // Check for cycle start
        if (R == initial_seed)
        {
            printf("%d\t%d\t\t%d  <-- Cycle Repeats R0\n", count, R, R);
            break;
        }

        printf("%d\t%d\t\t%d\n", count, R, R);
        count++;
    }

    printf("\nCycle detected after %d unique random numbers.\n", count);

    return 0;
}
