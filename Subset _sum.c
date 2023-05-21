#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

void generateSubsets(int set[], bool subset[], int index, int size)
{
    // Print the current subset
    printf("{ ");
    for (int i = 0; i < index; i++)
    {
        if (subset[i])
        {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");

    // Generate subsets recursively
    for (int i = index; i < size; i++)
    {
        subset[i] = true;
        generateSubsets(set, subset, i + 1, size);
        subset[i] = false;
    }
}

int main()
{
    int size;
    int set[MAX_SIZE];

    printf("Enter the size of the set: ");
    scanf("%d", &size);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &set[i]);
    }

    bool subset[MAX_SIZE] = {false};

    printf("All subsets of the given set:\n");
    generateSubsets(set, subset, 0, size);

    return 0;
}
