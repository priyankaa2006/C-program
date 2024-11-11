#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Function to perform DFS and fill the stack with the topological order
void topologicalSortUtil(int v, int visited[], int stack[], int *top, int graph[MAX][MAX], int n);

// Function to perform topological sorting
void topologicalSort(int graph[MAX][MAX], int n);

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int i, u, v;
    
    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    // Input the edges
    printf("Enter the edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        
        // Validate the edge input (check if u and v are within the range)
        if (u >= 0 && u < n && v >= 0 && v < n) {
            graph[u][v] = 1;
        } else {
            printf("Invalid edge: %d -> %d. Vertices should be in the range 0 to %d.\n", u, v, n-1);
        }
    }
    
    // Print topological ordering of vertices
    printf("Topological ordering of the vertices:\n");
    topologicalSort(graph, n);
    
    return 0;
}

void topologicalSortUtil(int v, int visited[], int stack[], int *top, int graph[MAX][MAX], int n) {
    visited[v] = 1;
    
    // Explore all adjacent vertices of v
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, stack, top, graph, n);
        }
    }
    
    // Push the vertex to the stack once all its neighbors are visited
    stack[(*top)++] = v;
}

void topologicalSort(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};  // Array to track visited vertices
    int stack[MAX];           // Stack to store topological sort
    int top = 0;              // Pointer to the top of the stack
    
    // Perform DFS for each vertex
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack, &top, graph, n);
        }
    }
    
    // Print the topological order by popping the stack
    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
