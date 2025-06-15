// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
#include<stdio.h>
void floydWarshall(vector<vector<int>> &graph) {
	int i,j,k;
    int V = graph.size();
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if ((graph[i][j] == -1 || 
                    graph[i][j] > (graph[i][k] + graph[k][j]))
                    && (graph[k][j] != -1 && graph[i][k] != -1))
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main() {
	int i,j;
    vector<vector<int>> graph = {
        {0, 4, -1, 5, -1},
        {-1, 0, 1, -1, 6},
        {2, -1, 0, 3, -1},
        {-1, -1, 1, 0, 2},
        {1, -1, -1, 4, 0}
    };
    floydWarshall(graph);
    for(i = 0; i<graph.size(); i++) {
        for(j = 0; j<graph.size(); j++) {
            printf(" ";graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}

