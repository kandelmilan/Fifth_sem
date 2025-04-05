#include <stdio.h>

int main()
{
    int a, n, t1 = 0, t2 = 1, q, r, temp;
    printf("Enter the modulus n: ");
    scanf("%d", &n);
    printf("Enter the number a: ");
    scanf("%d", &a);
    int n0 = n, a0 = a;
    while (a != 0)
    {
        q = n / a;
        r = n % a;
        n = a;
        a = r;
        temp = t1 - q * t2;
        t1 = t2;
        t2 = temp;
    }
    if (n != 1)
    {
        printf("Multiplicative inverse doesnot exist for number %d in Z%d.\n", a0, n);
    }
    else
    {
        if (t1 < 0)
        {
            t1 = t1 + n0;
        }
        printf("Multiplicative inverse of %d in Z%d is : %d.\n", a0, n0, t1);
    }
    return 0;
}
