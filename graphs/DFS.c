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

    // DFS(G, 0, 4);
    // BFS(G, 0);

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

void DFS(Graph G, int obj, int start) {
    G->visited[start] = 1;
    if(start == obj) {
        return;
    }
    link tmp = G->adj[start];
    while(tmp) {
        if(G->visited[tmp->w] == 0) {
            G->previous[tmp->w] = start;
            DFS(G, obj, tmp->w);
        }
        tmp = tmp->next;
    }
}
