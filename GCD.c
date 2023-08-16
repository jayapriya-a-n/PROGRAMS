#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}
