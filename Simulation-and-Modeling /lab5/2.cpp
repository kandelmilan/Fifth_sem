// election process
// a population of vector are distribbuted between the democratic(D), Republican(R) and independent(I)parties
// each election the voting population p=[D,R,I] obeys the distribution
// in 2004 election, the voters were distributed according to the distribution vector
// p0=[0.48,0.51,0.1]
// Q:the next ecpected population outcome od the 2008 ekection??
// A: p0*T2 -0.70*0.48+0.10*0.51+0.30*0.10-0.417
#include <stdio.h>

int main()
{
    // Initial population distribution in 2004: D, R, I
    double p0[3] = {0.48, 0.51, 0.10};

    // Transition matrix T² (squared matrix showing behavior over 2 elections)
    // Only first row is used since we are calculating p2008[Democratic]
    double T2[3][3] = {
        {0.70, 0.20, 0.10}, // D row
        {0.10, 0.80, 0.10}, // r
        {0.30, 0.30, 0.40}  // i
    };

    double p2008[3] = {0};

    // Matrix-vector multiplication: p2008 = p0 * T²
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            p2008[j] += p0[k] * T2[k][j];
        }
    }

    // Display population distribution for 2008 election
    printf("Expected population outcome for the 2008 election:\n");
    printf("Democratic: %.3lf\n", p2008[0]);
    printf("Republican: %.3lf\n", p2008[1]);
    printf("Independent: %.3lf\n", p2008[2]);

    return 0;
}