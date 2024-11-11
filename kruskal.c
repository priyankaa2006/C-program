#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

// Find function with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);  // Path compression
    return subsets[i].parent;
}

// Union function by rank
void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function for sorting edges
int cmp(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

// Kruskal's algorithm to find the MST
void KruskalMST(Edge edges[], int V, int E) {
    Edge result[MAX];  // To store the MST
    int e = 0;         // Count of edges in MST
    int i = 0;         // Initial index for sorted edges

    // Sorting edges by their weight
    qsort(edges, E, sizeof(edges[0]), cmp);

    // Allocate memory for subsets
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    // Initialize the subsets for all vertices
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges and construct MST
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        // Find roots of the two vertices
        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        // If they are in different sets, include this edge in the MST
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the MST
    printf("Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);
        minimumCost += result[i].w;
    }

    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);

    // Free allocated memory
    free(subsets);
}

int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Edge array to store all edges
    Edge edges[MAX];

    printf("Enter the edges (u v w) where u and v are 0-based vertex indices:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Call Kruskal's algorithm to find the MST
    KruskalMST(edges, V, E);

    return 0;
}
