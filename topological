#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void topologicalSortUtil(int v, int visited[], int stack[], int
*top, int graph[MAX][MAX], int n);
void topologicalSort(int graph[MAX][MAX], int n);
int main() {
 int n, e;
 int graph[MAX][MAX] = {0};
 int i, u, v;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the number of edges: ");
 scanf("%d", &e);
Ex. No:3(A)
Date:
 TOPOLOGICAL ORDERING
 printf("Enter the edges (u v):\n");
 for (i = 0; i < e; i++) {
 scanf("%d %d", &u, &v);
 graph[u][v] = 1;
 }
 printf("Topological ordering of the vertices:\n");
 topologicalSort(graph, n);
 return 0;
}
void topologicalSortUtil(int v, int visited[], int stack[], int
*top, int graph[MAX][MAX], int n) {
 visited[v] = 1;
 for (int i = 0; i < n; i++) {
 if (graph[v][i] && !visited[i]) {
 topologicalSortUtil(i, visited, stack, top, graph, n);
 }
 }
 stack[(*top)++] = v;
}
void topologicalSort(int graph[MAX][MAX], int n) {
 int visited[MAX] = {0};
 int stack[MAX];
 int top = 0;
 for (int i = 0; i < n; i++) {
 if (!visited[i]) {
 topologicalSortUtil(i, visited, stack, &top, graph, n);
 }
 }
 for (int i = top - 1; i >= 0; i--) {
 printf("%d ", stack[i]);
 }
 printf("\n");
}
