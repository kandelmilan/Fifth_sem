#include <stdio.h>

int power(int base, int exp, int mod)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result = (result * base) % mod;
    }
    return result;
}

int main()
{
    int p;
    int g;
    printf("Enter the prime number(p):");
    scanf("%d", &p);
    printf("Enter a primitive root (g):");
    scanf("%d", &g);
    int privateKeyA;
    int privateKeyB;
    printf("Enter the private key for User A:");
    scanf("%d", &privateKeyA);

    printf("Enter the private key for User B:");
    scanf("%d", &privateKeyB);

    int publicKeyA = power(g, privateKeyA, p);
    int publicKeyB = power(g, privateKeyB, p);

    int keyA = power(publicKeyB, privateKeyA, p);
    int keyB = power(publicKeyA, privateKeyB, p);

    printf("Public Key of A: %d\n", publicKeyA);
    printf("Public Key of B: %d\n", publicKeyB);
    printf("Shared Key at A: %d\n", keyA);
    printf("Shared Key at B: %d\n", keyB);

    return 0;
}
