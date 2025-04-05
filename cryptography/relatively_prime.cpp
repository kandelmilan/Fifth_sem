#include <stdio.h>

int gcd(int a, int b)
{
    int min = (a < b) ? a : b;
    for (int i = min; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    int a, b;

    printf("Enter the first positive integer:");
    scanf("%d", &a);

    printf("Enter the second positive integer:");
    scanf("%d", &b);

    if (a <= 0 || b <= 0)
    {
        printf("Please enter the positive interger");
        return 1;
    }

    int result = gcd(a, b);

    if (result == 1)
        printf("%d and %d are relatively prime .\n", a, b);
    else
        printf("%d and %d are not  relatively prime .\n", a, b);

    return 0;
}