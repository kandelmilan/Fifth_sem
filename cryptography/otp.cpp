#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char plaintext[100], ciphertext[100], key[100];
    int i;

    printf("Enter lowercase plaintext: ");
    scanf("%s", plaintext);

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        key[i] = (rand() % 26) + 97;
    }
    key[i] = '\0';

    printf("Generated Key: %s\n", key);

    printf("---------Encryption---------\n");
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        ciphertext[i] = ((plaintext[i] - 97 + (key[i] - 97)) % 26) + 97;
    }
    ciphertext[i] = '\0';

    printf("Encrypted Ciphertext: %s\n", ciphertext);

    printf("---------Decryption---------\n");
    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        plaintext[i] = ((ciphertext[i] - 97 - (key[i] - 97) + 26) % 26) + 97;
    }
    plaintext[i] = '\0';

    printf("Decrypted Plaintext: %s\n", plaintext);

    return 0;
}
