#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFSUtil(int adj[MAX][MAX], int n, int source, int visited[MAX]) {
    // Mark the current node as visited and print it
    visited[source] = 1;
    printf("%d ", source);

    // Recur for all neighbors of the current node
    for (int i = 0; i < n; i++) {
        if (adj[source][i] == 1 && !visited[i]) {
            DFSUtil(adj, n, i, visited);
        }
    }
}

void DFS(int adj[MAX][MAX], int n, int source) {
    int visited[MAX] = {0}; // Array to track visited nodes

    printf("DFS Traversal: ");
    DFSUtil(adj, n, source, visited);
    printf("\n");
}

int main() {
    int n, source;
    int adj[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source vertex (0-based index): ");
    scanf("%d", &source);

    DFS(adj, n, source);

    return 0;
}