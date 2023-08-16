#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform randomised rounding
int randomisedRounding(double value)
{
    double random = (double)rand() / RAND_MAX;
    if (random < value - (int)value)
    {
        return (int)value + 1;
    }
    else
    {
        return (int)value;
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    double input;
    printf("Enter a decimal value: ");
    scanf("%lf", &input);

    int rounded = randomisedRounding(input);
    printf("Randomised rounded value: %d\n", rounded);

    return 0;
}
