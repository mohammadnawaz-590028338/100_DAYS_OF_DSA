#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];
int queue[100], front = 0, rear = 0;

// add edge (undirected)
void addEdge(int u, int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = adj[u];
    adj[u] = temp;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = u;
    temp->next = adj[v];
    adj[v] = temp;
}

void BFS(int s) {
    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, s;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    scanf("%d", &s); // source

    BFS(s);

    return 0;
}
