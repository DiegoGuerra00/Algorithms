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

UnionFind ufSetInit(int n) {
    UnionFind uf = malloc(sizeof(*uf));
    uf->leader = malloc(n * sizeof(int));
    uf->size = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        uf->leader[i] = i;
        uf->size[i] = 1;
    }

    return uf;
}

int ufFindSet(UnionFind uf, int x) {
    if(uf->leader[x] == x) {
        return x;
    }

    uf->leader[x] = ufFindSet(uf, uf->leader[x]);

    return uf->leader[x];
}

void ufUnion(UnionFind uf, int x, int y) {
    int lx = ufFindSet(uf, x);
    int ly = ufFindSet(uf, y);

    if(uf->size[lx] >= uf->size[ly]) {
        uf->leader[lx] = ly;
        uf->size[ly] += uf->size[lx];
    }
    else {
        uf->leader[ly] = lx;
        uf->size[lx] += uf->size[ly];
    }
}

Edge kruskal(int V, int E, Edge edges) {
    Edge MST = malloc((V - 1) * sizeof(*MST));

    // Sorts the edges array with bubble sort
    // TODO better sort
    for(int i = 0; i < E; i++) {
        for(int j = 0; j < E - i; j++) {
            if(j+1 < E) {
                if(edges[j].weight > edges[j+1].weight) {
                    int auxU = edges[j].u;
                    int auxV = edges[j].v;
                    int auxW = edges[j].weight;
                    edges[j].u = edges[j+1].u;
                    edges[j].v = edges[j+1].v;
                    edges[j].weight = edges[j+1].weight;
                    edges[j+1].u = auxU;
                    edges[j+1].v = auxV;
                    edges[j+1].weight = auxW;
                }
            }
        }
    }

    UnionFind uf = ufSetInit(V);
    int k = 0;
    for(int i = 0; i < E; i++) {
        if(ufFindSet(uf, edges[i].u) != ufFindSet(uf, edges[i].v)) {
            ufUnion(uf, edges[i].u, edges[i].v);
            MST[k] = edges[i];
            k += 1;
        }
    }
    
    return MST;
}
