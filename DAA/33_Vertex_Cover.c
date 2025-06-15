#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
// Function to find the Vertex Cover using the approximation algorithm
void vertexCover(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
bool visited[MAX_VERTICES] = {false}; // Array to mark visited vertices
for (int u = 0; u < V; u++) {
// If the vertex u is not yet visited
if (!visited[u]) {
// Check all adjacent vertices of u
for (int v = 0; v < V; v++) {
// If there's an edge from u to v and v is not visited
if (graph[u][v] && !visited[v]) {
// Include both u and v in the vertex cover
visited[u] = true;
visited[v] = true;
break; // Move to the next vertex u
}
}
}
}
// Print the Vertex Cover
printf("The Vertex Cover is: ");
for (int i = 0; i < V; i++) {
if (visited[i]) {
printf("%d ", i);
}
}
printf("\n");
}
int main() {
int V; // Number of vertices
printf("Enter the number of vertices: ");
scanf("%d", &V);
int graph[MAX_VERTICES][MAX_VERTICES];
printf("Enter the adjacency matrix:\n");
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
}
}
vertexCover(graph, V);
printf("\nName:Cosmc Gautam\tRoll no.:07");
return 0;
}