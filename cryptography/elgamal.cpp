#include <stdio.h>

// Function to compute (base^exp) % mod efficiently
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    long long p, g, x, y, k, m, c1, c2, s, s_inv = -1, decrypted;

    // Key Generation
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root of p (g): ");
    scanf("%lld", &g);

    printf("Enter private key x (x < p): ");
    scanf("%lld", &x);

    // Compute public key y = g^x mod p
    y = mod_exp(g, x, p);

    printf("\nPublic Key: (p = %lld, g = %lld, y = %lld)\n", p, g, y);
    printf("Private Key: x = %lld\n", x);

    // Message input
    printf("\nEnter message to encrypt (m < p): ");
    scanf("%lld", &m);

    // Take random k from user
    printf("Enter a random integer k : ");
    scanf("%lld", &k);

    // Compute c1 = g^k mod p
    c1 = mod_exp(g, k, p);

    // Compute s = y^k mod p
    s = mod_exp(y, k, p);

    // Compute c2 = (m * s) mod p
    c2 = (m * s) % p;

    printf("\nEncrypted message: (c1 = %lld, c2 = %lld)\n", c1, c2);

    // Decryption
    // Compute s = c1^x mod p
    s = mod_exp(c1, x, p);

    // Find modular inverse of s (s_inv)
    for (long long i = 1; i < p; i++)
    {
        if ((s * i) % p == 1)
        {
            s_inv = i;
            break;
        }
    }

    // Decrypt message: m = (c2 * s_inv) mod p
    decrypted = (c2 * s_inv) % p;

    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
