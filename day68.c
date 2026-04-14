#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// dequeue
int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++; // count incoming edges
    }

    // add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // if count != n → cycle exists
    if (count != n) {
        printf("Cycle exists! No Topological Order\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
