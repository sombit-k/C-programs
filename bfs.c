#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void BFS(int adj[MAX][MAX], int n, int source) {
    int visited[MAX] = {0}; // Array to track visited nodes
    int queue[MAX], front = 0, rear = 0; // Queue for BFS traversal

    // Start BFS from the source node
    queue[rear++] = source;
    visited[source] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Traverse all neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
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

    BFS(adj, n, source);

    return 0;
}