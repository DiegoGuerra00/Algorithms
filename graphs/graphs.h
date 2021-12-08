#ifndef graphs 
#define graphs

/* Structs */

/**
 * @brief Struct defining each component of adjacency list
 * 
 * @param w Index of one of the vertex of the edge
 * @param weight Weight of the edge
 * @param next Pointer to the next item
 */
typedef struct node *link;
struct node {
    int w;
    int weight;
    link next;
};

/**
 * @brief Struct defining the graph
 * 
 * @param V Number of vertex of the graph
 * @param E Number of edges of the graph
 * @param adj Adjacency list with the edges
 * @param visited Array to tell if a vertex was visited in the search
 * @param  previous Array to store the path founf during a search
 */
typedef struct graph *Graph;
struct graph{
    int V;
    int E;
    link *adj;
    int *visited;
    int *previous; //armazena qual vértice foi visitado antes, para contruir um caminho
};

/**
 * @brief Struct defining the edges
 * 
 * @param u One of the vertex of the edge
 * @param v The other vertex of the edge
 * @param weight Weight of the edge
 * @param visited indicates if the edge has been visited by the search(when value is 1) or not(when 0)
 */
typedef struct edge *Edge;
struct edge {
    int u; 
    int v;
    int weight;
    int visited;
};

/**
 * @brief Struct defining a union-find set
 * 
 * @param leader Array with the leader of each vertex, used to store the UF in the shape of a tree
 * @param size Stores the size of each branch of the tree in the UF set
 */
typedef struct unionFind *UnionFind;
struct unionFind {
    int *leader;
    int *size;
};

/**
 * @brief Struct defining a queue
 * 
 * @param items Array with the queue items
 * @param front Front of the queue
 * @param rear End of the queue
 * @param size Max size of the queue
 * @param elementCount Actual number of elements on the queue
 */
typedef struct queue *Queue;
struct queue {
    int *items;
    int front;
    int rear;
    int size;
    int elementCount;
};

/* Graphs functions */

/**
 * @brief Create a Graph object
 * 
 * @param V Number of vertex in the graph
 * @return Graph 
 */
Graph createGraph (int);

/**
 * @brief Insert a edge in the adjacency list
 * 
 * @param head First item of the adjscency list
 * @param w The vertex in the end of the edge
 * @param weight weight of the edge
 * @return link 
 */
link listInsert(link, int, int);

/**
 * @brief Adds a edge in the graph, calling listInsertEdge
 * 
 * @param G The graph
 * @param u One of the vertex of the edge
 * @param v The other vertex of the edge
 * @param weight The weight of the edge
 */
void graphInsertEdge(Graph, int , int, int);

/**
 * @brief Create the Union-Find set, setting each vertex as it's own leader
 * 
 * @param n Size of the UF
 * @return UnionFind 
 */
UnionFind ufSetInit(int);

/**
 * @brief Finds the leader of a vertex in the Union-Find, with path compression for better efficiency
 * 
 * @param uf The UF set
 * @param x The vertex used in the search
 * @return int 
 */
int ufFindSet(UnionFind, int);

/**
 * @brief Do the union of two Union_find sets
 * 
 * @param uf The UF sets
 * @param x Leader of the first set
 * @param y Leader of the second set
 */
void ufUnion(UnionFind, int, int);

/**
 * @brief Kruskal algorithm to find the MST of the graph
 * 
 * @param V Number of vertex in the graph
 * @param E Number of edges in the graph
 * @param edges Array with the edges of the graph
 * @return Edge 
 */
Edge kruskal(int, int, Edge);

/**
 * @brief Perform a Depth first search in the graph
 * 
 * @param G The graph
 * @param obj The objective of the search
 * @param start The start of the search
 */
void DFS(Graph, int, int);

/**
 * @brief Perform a Breath first search in the graph
 * 
 * @param G The graph
 * @param start The start of the search
 */
void BFS(Graph, int);

/* Queue functions */

/**
 * @brief Create a Queue object
 * 
 * @param size Max size of the queue
 * @return Queue 
 */
Queue createQueue(int);

/**
 * @brief Dequeue an item from the queue
 * 
 * @param q The queue
 * @return int 
 */
int dequeue(Queue);

/**
 * @brief Adds an item to the queue
 * 
 * @param q The queue
 * @param n The item to be added
 */
void enqueue(Queue, int);

/**
 * @brief Returns if the queue is empty or not
 * 
 * @param q The queue
 * @return int 
 */
int queueIsEmpty(Queue);

#endif