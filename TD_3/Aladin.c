#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void BFS(int mat[MAX][MAX], int N, int start, int target, int parent[MAX], int visited[MAX]) {
    Queue q;
    initQueue(&q);
    
    visited[start] = 1;
    enqueue(&q, start);
    parent[start] = -1;
    
    while (!isEmpty(&q)) {
        int current = dequeue(&q);

        if (current == target) {
            return;
        }

        for (int i = 0; i < N; i++) {
            if (mat[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = current;
                enqueue(&q, i);
            }
        }
    }
}

int getPathLength(int parent[MAX], int start, int target) {
    int pathLength = 0;
    
    for (int at = target; at != -1; at = parent[at]) {
        pathLength++;
    }
    
    return pathLength - 1;
}

void countKingdoms(int mat[MAX][MAX], int N, int visited[MAX], int* kingdomCount) {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            BFS(mat, N, i, -1, visited, visited);
            (*kingdomCount)++;
        }
    }
}

int main() {
    int N, M;
    int mat[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int parent[MAX] = {-1};
    int kingdomCount = 0;
    int a, b;

    FILE *file = fopen("input.txt", "r");

    fscanf(file, "%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);
        mat[u-1][v-1] = 1;
        mat[v-1][u-1] = 1;
    }

    fscanf(file, "%d %d", &a, &b);
    fclose(file);

    countKingdoms(mat, N, visited, &kingdomCount);

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    BFS(mat, N, a - 1, b - 1, parent, visited);

    printf("%d\n", kingdomCount);
    
    if (visited[b - 1]) {
        int pathLength = getPathLength(parent, a - 1, b - 1);
        printf("%d\n", pathLength);
    } else {
        printf("No path\n");
    }

    return 0;
}