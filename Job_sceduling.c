#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int jobNumber;
    int processingTime;
} Job;

void swap(Job* a, Job* b)
{
    Job temp = *a;
    *a = *b;
    *b = temp;
}

int calculateCompletionTime(Job jobs[], int n)
{
    int completionTime = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        currentTime += jobs[i].processingTime;
        completionTime += currentTime;
    }
    return completionTime;
}

void findOptimalSchedule(Job jobs[], int n, int currentLevel, int* minCompletionTime, int* currentCompletionTime, int* included, int* result)
{
    if (currentLevel == n) {
        int completionTime = calculateCompletionTime(jobs, n);
        if (completionTime < *minCompletionTime)
        {
            *minCompletionTime = completionTime;
            for (int i = 0; i < n; i++)
            {
                result[i] = included[i];
            }
        }
        return;
    }

    for (int i = currentLevel; i < n; i++)
    {
        swap(&jobs[currentLevel], &jobs[i]);
        included[currentLevel] = 1;
        *currentCompletionTime += jobs[currentLevel].processingTime;

        if (*currentCompletionTime < *minCompletionTime)
        {
            findOptimalSchedule(jobs, n, currentLevel + 1, minCompletionTime, currentCompletionTime, included, result);
        }

        *currentCompletionTime -= jobs[currentLevel].processingTime;
        included[currentLevel] = 0;
        swap(&jobs[currentLevel], &jobs[i]);
    }
}

void printSchedule(Job jobs[], int n, int result[])
{
    printf("Job Schedule: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", jobs[result[i]].jobNumber);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job* jobs = (Job*)malloc(n * sizeof(Job));
    int* included = (int*)calloc(n, sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));

    printf("Enter the processing times for each job:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Job %d: ", i + 1);
        scanf("%d", &jobs[i].processingTime);
        jobs[i].jobNumber = i + 1;
    }

    int minCompletionTime = calculateCompletionTime(jobs, n);
    int currentCompletionTime = 0;

    findOptimalSchedule(jobs, n, 0, &minCompletionTime, &currentCompletionTime, included, result);

    printf("Optimal Schedule: ");
    printSchedule(jobs, n, result);
    printf("Minimum Completion Time: %d\n", minCompletionTime);

    free(jobs);
    free(included);
    free(result);

    return 0;
}
