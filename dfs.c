#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
 int data;
 struct Node* next;
} Node;
void addEdge(Node* adj[], int u, int v) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = v;
 newNode->next = adj[u];
 adj[u] = newNode;
}
void DFSUtil(Node* adj[], int v, int visited[]) {
 visited[v] = 1;
 for (Node* p = adj[v]; p != NULL; p = p->next) {
 if (!visited[p->data]) {
 DFSUtil(adj, p->data, visited);
 }
 }
}
int isConnected(Node* adj[], int n) {
 int visited[MAX] = {0};
 DFSUtil(adj, 0, visited);
 for (int i = 0; i < n; i++) {
 if (!visited[i]) {
 return 0;
 }
 }
 return 1;
}
int main() {
 int n, e;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the number of edges: ");
 scanf("%d", &e);
 Node* adj[MAX] = {0};
 printf("Enter the edges (u v):\n");
 for (int i = 0; i < e; i++) {
 int u, v;
 scanf("%d %d", &u, &v);
 addEdge(adj, u, v);
 addEdge(adj, v, u); // because the graph is undirected
 }
 if (isConnected(adj, n)) {
 printf("The graph is connected.\n");
 } else {
 printf("The graph is not connected.\n");
 }
 return 0;
}
