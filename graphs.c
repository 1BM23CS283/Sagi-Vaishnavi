#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20  
struct Queue {
    int items[MAX];
    int front;
    int rear;
};
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}
bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}
bool isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}
void bfs(int graph[MAX][MAX], int start, int vertices) {
    bool visited[MAX] = {false};  
    struct Queue q;
    initQueue(&q);
    visited[start] = true;
    enqueue(&q, start);
    printf("BFS Traversal starting from vertex %d: ", start);
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}


int main() {
    int graph[MAX][MAX], vertices, edges, u, v, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u v) where there is an edge between u and v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since the graph is undirected
    }
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(graph, start, vertices);

    return 0;
}
