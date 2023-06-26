#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate all permutations of a string
void permute(char *str, int start, int end)
{
    if (start == end)
    {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap((str + start), (str + i));
        permute(str, start + 1, end);
        swap((str + start), (str + i));  // backtrack
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // remove newline character

    int n = strlen(str);
    printf("Permutations of the string:\n");
    permute(str, 0, n - 1);

    return 0;
}
