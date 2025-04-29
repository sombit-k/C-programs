#include <stdio.h>
#include <limits.h>

#define MAX 100

void prims(int adj[MAX][MAX], int n) {
    int parent[MAX];       // Array to store the MST
    int key[MAX];          // Key values to pick the minimum weight edge
    int mstSet[MAX] = {0}; // To track vertices included in MST

    // Initialize all keys as infinite and parent as -1
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    // Start from the first vertex
    key[0] = 0; // Make key 0 so that this vertex is picked first

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum key value not yet included in MST
        int min = INT_MAX, u;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Include the picked vertex in the MST
        mstSet[u] = 1;

        // Update key and parent for the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, adj[i][parent[i]]);
    }
}

int main() {
    int n;
    int adj[MAX][MAX], inc[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the incidence matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &inc[i][j]);
        }
    }

    prims(adj, n);

    return 0;
}