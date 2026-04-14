#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
bool visited[MAX];
int n;

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle detected
            }
        }
    }
    return false;
}

int main() {
    int e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
