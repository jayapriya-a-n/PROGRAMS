#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount)
{
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int subRes = dp[i - coins[j]];
                if (subRes != INT_MAX && subRes + 1 < dp[i])
                {
                    dp[i] = subRes + 1;
                }
            }
        }
    }

    return dp[amount];
}

int main()
{
    int coins[] = {1, 2, 5, 10};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int min = minCoins(coins, n, amount);

    printf("Minimum number of coins required: %d\n", min);

    return 0;
}
