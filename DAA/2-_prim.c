#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph *g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int min_key(int key[], int mst_set[], int V) {
    int min_val = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (key[v] < min_val && !mst_set[v]) {
            min_val = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void print_mst(int parent[], Graph *g) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < g->V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g->graph[i][parent[i]]);
    }
}

void prim_mst(Graph *g) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mst_set[MAX_VERTICES] = {0};

    for (int i = 0; i < g->V; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < g->V - 1; count++) {
        int u = min_key(key, mst_set, g->V);
        mst_set[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && !mst_set[v] && g->graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->graph[u][v];
            }
        }
    }

    print_mst(parent, g);
}

int main() {
    Graph g;
    int vertices, edges, u, v, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    init_graph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(&g, u, v, weight);
    }

    prim_mst(&g);

    printf("Name: Cosmic Gautam\n");
    printf("Roll no.: 07\n");

    return 0;
}