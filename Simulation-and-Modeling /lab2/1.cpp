// Lab -2 Lab Related with Random Number Generation
// Activity 1: Use Linear Congruential Method (LCM) to generate random numbers. Write a C/C+ Program to generates random numbers
// Your program should ask for user input like how many digits, how many random numbers
// what is the initial value (RO) constant values like: a and c
// Then calculate the Random number using Ri+1= (a*Ritc) mod m where m should be determine based on the number of digits

#include <stdio.h>
#include <math.h>

int main()
{
    int num_digits, num_randoms;
    int R, a, c, m;

    printf("Enter number of digits for each random number: ");
    scanf("%d", &num_digits);

    printf("Enter how many random numbers to generate: ");
    scanf("%d", &num_randoms);

    printf("Enter initial seed value (R0): ");
    scanf("%d", &R);

    printf("Enter multiplier constant (a): ");
    scanf("%d", &a);

    printf("Enter increment constant (c): ");
    scanf("%d", &c);

    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("\nRandom Numbers Generated Using LCM:\n");
    printf("-----------------------------------------------------\n");
    printf("SN\tR(i)\t\tRandom Number (0 to m-1)\n");
    printf("-----------------------------------------------------\n");

    printf("0\t%d\t\t%d\n", R, R);
    for (int i = 1; i <= num_randoms; i++)
    {
        R = (a * R + c) % m;
        printf("%d\t%d\t\t%d\n", i, R, R);
    }

    return 0;
}
