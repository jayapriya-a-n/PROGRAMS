#include <stdio.h>

int sum_of_digits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n % 10) + sum_of_digits(n / 10); // returns the value of sum
    }
}

int main()
{
    int n,sum;
    printf("Enter a number: ");
    scanf("%d",&n);
    sum=sum_of_digits(n);
    printf("The sum of digits of %d is %d\n", n,sum);
    return 0;
}
