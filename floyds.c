#include <stdio.h>
#include <stdlib.h>
#define INF 9999  // A large number to represent infinity

int cost[10][10], a[10][10];

void all_paths(int cost[10][10], int a[10][10], int n);
int min1(int a, int b);

int main() {
    int i, j, n;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    // Initialize the cost matrix with values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // Initialize the 'a' matrix with the same values
            a[i][j] = cost[i][j];

            // If there is no edge between i and j, set cost as infinity (except diagonal)
            if (i != j && cost[i][j] == 0) {
                a[i][j] = INF;
            }
        }
    }

    // Call the function to calculate the shortest paths
    all_paths(cost, a, n);

    printf("\nShortest path obtained is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == INF)
                printf("\tINF");
            else
                printf("\t%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to calculate the shortest paths using Floyd-Warshall algorithm
void all_paths(int cost[10][10], int a[10][10], int n) {
    int i, j, k;
    // Floyd-Warshall algorithm to compute the shortest paths
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Update the shortest path considering the intermediate vertex k
                a[i][j] = min1(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

// Helper function to return the minimum of two values
int min1(int a, int b) {
    return (a < b) ? a : b;
}
