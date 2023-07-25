#include <stdio.h>

void coinChange(int coins[], int n, int amount)
{
    int coinCount[n];

    for (int i = 0; i < n; i++)
    {
        coinCount[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            coinCount[i]++;
        }
    }

    printf("Maximum number of coins required:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        if (coinCount[i] > 0)
        {
            printf("%d coin(s) of denomination %d\n", coinCount[i], coins[i]);
        }
    }
}

int main()
{
    int coins[] = {10, 5, 2, 1};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    coinChange(coins, n, amount);

    return 0;
}
