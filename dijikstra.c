#include <stdio.h>
#define INF 999  // Defining infinity as a large number

int main() {
    int n, cost[15][15], i, j, s[15], v, dist[15], num, min;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost matrix (adjacency matrix)
    printf("Enter the cost of the edges (enter 999 if no edge or self-loop):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input the source vertex
    printf("Enter the Source vertex: ");
    scanf("%d", &v);

    // Initialize the `dist` array with the cost of edges from source `v`
    for (i = 1; i <= n; i++) {
        s[i] = 0;         // Mark all vertices as unvisited
        dist[i] = cost[v][i]; // Initialize distances from source
    }
    
    // Distance to source is 0
    dist[v] = 0;
    s[v] = 1;  // Mark source as visited
    
    // Implement Dijkstra's algorithm
    for (num = 1; num <= n - 1; num++) {
        min = INF;
        
        // Find the unvisited vertex with the minimum distance
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && dist[i] < min) {
                min = dist[i];
                j = i;  // Store the index of the vertex with the minimum distance
            }
        }

        // Mark the selected vertex as visited
        s[j] = 1;

        // Update the distances of the adjacent vertices
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && dist[i] > dist[j] + cost[j][i] && cost[j][i] != INF) {
                dist[i] = dist[j] + cost[j][i]; // Relax the edge
            }
        }
    }

    // Output the results (shortest path from source `v`)
    printf("VERTEX\tDESTINATION\tCOST\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t%d\t\t%d\n", v, i, dist[i]);
    }

    return 0;
}
