#include <stdio.h>

#define MAX_ITEMS 10

typedef struct {
    int weight;
    int value;
} Item;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, Item items[], int n)
{
    int i, currWeight, currValue, maxValue;
    float bound;

    int queue[MAX_ITEMS][2]; // [][0] -> level, [][1] -> value
    int front = -1, rear = -1;
    int level = 0;
    int value = 0;
    int maxVal = 0;

    queue[++rear][0] = level;
    queue[rear][1] = value;

    while (front != rear)
    {
        level = queue[++front][0];
        value = queue[front][1];

        if (level == n - 1)
        {
            if (value > maxVal)
                maxVal = value;
            continue;
        }

        currWeight = 0;
        currValue = 0;

        for (i = level + 1; i < n; i++)
        {
            currWeight = items[i].weight;
            currValue = items[i].value;

            if (currWeight <= capacity)
            {
                if (value + currValue > maxVal)
                    maxVal = value + currValue;
                bound = value + (float)(capacity - currWeight) * currValue / currWeight;
                if (bound > maxVal)
                {
                    queue[++rear][0] = i;
                    queue[rear][1] = value + currValue;
                }
            }
        }
    }

    return maxVal;
}

int main()
{
    Item items[MAX_ITEMS];
    int capacity, n, i;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int maxValue = knapsack(capacity, items, n);

    printf("Maximum value achievable: %d\n", maxValue);

    return 0;
}
