#include <stdio.h>
int additive_inverse(int a, int n)
{
    return (n - a) % n;
}
int main()
{
    int a, n;
    printf("Enter the number (a):");
    scanf("%d", &a);

    printf("Enter the modulo (n):");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("the modulo must be positive");
        return 1;
    }

    int inverse = additive_inverse(a, n);
    printf("the additive inverse of %d in Z%d is :%d\n", a, n, inverse);

    return 0;
}