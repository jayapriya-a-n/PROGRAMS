#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX]; // Adjacency matrix to represent the graph
int path[MAX]; // Array to store the current path
int visited[MAX]; // Array to track visited vertices
int numVertices; // Number of vertices in the graph
int minCost = INT_MAX; // Variable to store the minimum cost

// Function to calculate the total cost of the given path
int calculateCost(int path[], int n)
{
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    return cost;
}

// Recursive function to generate all possible permutations of the path
void tsp(int currVertex, int count)
{
    visited[currVertex] = 1;
    path[count++] = currVertex;

    // Base case: If all vertices are visited, check if it forms a better path
    if (count == numVertices)
    {
        int currentCost = calculateCost(path, numVertices);
        if (currentCost < minCost)
        {
            minCost = currentCost;
        }
    }
    else
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (!visited[i])
            {
                tsp(i, count);
            }
        }
    }

    visited[currVertex] = 0; // Mark the current vertex as unvisited
}

int main()
{
    printf("Enter the number of vertices in the graph (max 10): ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    tsp(0, 0); // Start from vertex 0

    printf("Minimum cost of the Traveling Salesman tour: %d\n", minCost);

    return 0;
}
