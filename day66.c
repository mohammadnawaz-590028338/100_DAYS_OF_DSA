#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

// DFS function
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle detected
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

int main() {
    int e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
