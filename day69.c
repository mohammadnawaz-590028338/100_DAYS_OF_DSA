#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
int dist[MAX];
bool visited[MAX];
int n;

// find vertex with minimum distance
int minDistance() {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if graph is directed
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
