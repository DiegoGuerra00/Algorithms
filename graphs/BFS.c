#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

int main() {
    /* Graph G = createGraph(5);
    graphInsertEdge(G, 0, 3, 5);
    graphInsertEdge(G, 2, 1, 9);
    graphInsertEdge(G, 4, 2, 7);
    graphInsertEdge(G, 3, 1, 1);
    graphInsertEdge(G, 2, 3, 13); */

    return 0;
}

Graph createGraph (int V) {
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));
    G->visited = malloc(V * sizeof(int));
    G->previous = malloc(V * sizeof(int));
    for(int i = 0; i < V; i++) {
        G->adj[i] = NULL;
        G->visited[i] = 0;
        G->previous[i] = -1;
    }

    return G;
}

link listInsert(link head, int w, int weight) {
    link p = malloc(sizeof(*p));
    p->w = w;
    p->weight = weight;
    p->next = head;
    
    return p;
}

void graphInsertEdge(Graph G, int u, int v, int weight) {
    G->adj[u] = listInsert(G->adj[u], v, weight);
    G->adj[v] = listInsert(G->adj[v], u, weight);
    G->E += 1;
}

Queue createQueue(int size) {
    Queue q = malloc(sizeof(*q));
    q->front = 0;
    q->rear = -1;
    q->items = malloc(size * sizeof(int));
    q->elementCount = 0;
    q->size = size;

    return q;
}

int dequeue(Queue q) {
    if(q->elementCount > 0) {
        int data = q->items[q->front];
        q->front = (q->front+1) % q->size;
        q->elementCount--;

        return data;
    }
}

void enqueue(Queue q, int n) {
    if(q->elementCount < q->size) {
        q->rear = (q->rear+1) % q->size;
        q->items[q->rear] = n;
        q->elementCount++;
    }
}

int queueIsEmpty(Queue q) {
    return q->elementCount == 0;
}

void BFS(Graph G, int start) {
    Queue q = createQueue(G->V);
    G->visited[start] = 1;
    enqueue(q, start);
    link tmp;

    while(!queueIsEmpty(q)) {
        int u = dequeue(q);
        tmp = G->adj[u];
        while(tmp) {
            if(G->visited[tmp->w] == 0) {
                G->visited[tmp->w] = 1;
                enqueue(q, tmp->w);
                G->previous[tmp->w] = u; 
            }
            tmp = tmp->next;
        }
    }

    return;
}
