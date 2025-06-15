#include <stdio.h>
#include <limits.h>
#define V 3  // Number of vertices in the graph
void floydWarshall(int graph[V][V]) {
	int i,j,k;
    int dist[V][V];  // Output matrix that will have the shortest distances
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != -1 && dist[k][j] != -1 &&
                    (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print the shortest distance matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 4, 11},
        {6, 0,  2},
        {3, -1, 0},
    };
    floydWarshall(graph);
    printf("\nName:Cosmic Gautam	Rollno.:07");
    return 0;
}
