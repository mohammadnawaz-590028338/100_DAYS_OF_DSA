#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;
int n;

// push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    push(node); // push after visiting all neighbors
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

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    // call DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // print topological order
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
