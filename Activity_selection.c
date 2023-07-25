#include <stdio.h>

void activitySelection(int start[], int finish[], int n)
{
    printf("Selected activities:\n");

    int i = 0;
    printf("Activity %d\n", i + 1);

    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("Activity %d\n", j + 1);
            i = j;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];
    printf("Enter the start and finish times of activities:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    activitySelection(start, finish, n);

    return 0;
}
