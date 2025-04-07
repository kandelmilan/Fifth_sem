#include <stdio.h>

// Function to compute GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular inverse (for finding 'd')
int modInverse(int e, int phi)
{
    for (int d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
        {
            return d;
        }
    }
    return -1;
}

// Function for modular exponentiation (m^e mod n)
int modPow(int base, int exp, int mod)
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
    int p, q;
    printf("Enter the prime number(p):");
    scanf("%d", &p);
    printf("Enter a another prime number (q):");
    scanf("%d", &q);             // Step 1: Choose two prime numbers
    int n = p * q;               // Step 2: Compute n = p * q
    int phi = (p - 1) * (q - 1); // Step 3: φ(n) = (p-1)(q-1)

    int e; // Step 4: Choose e such that 1 < e < φ(n), and gcd(e, φ) = 1
    printf("Enter the an integer 'e' such that 1 < e < φ(n) :");
    scanf("%d", &e);
    while (gcd(e, phi) != 1)
    {
        e++;
    }

    int d = modInverse(e, phi); // Step 5: Compute d such that (e * d) ≡ 1 mod φ(n)

    // Step 6: Print public and private keys
    printf("Public Key: {e = %d, n = %d}\n", e, n);
    printf("Private Key: {d = %d, n = %d}\n", d, n);

    // Encryption
    int m; // plaintext
    printf("Enter message to encrypt (as number): ");
    scanf("%d", &m);

    int c = modPow(m, e, n); // c = m^e mod n
    printf("Encrypted message: %d\n", c);

    // Decryption
    int decrypted = modPow(c, d, n); // m = c^d mod n
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}
