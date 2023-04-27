#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// #define V 6 // Number of vertices in the graph
int V;

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n){
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++){
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's algorithm for a graph represented as an adjacency matrix
void dijkstra(int graph[V][V], int src){
    int dist[V];     // Array to store the shortest distance from src to each vertex
    bool sptSet[V]; // Array to keep track of vertices included in shortest path tree

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++){
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++){
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main(){
    printf("Enter Number of Vertices: ");
    scanf("%d",&V);
    int graph[V][V],src,i,j;
    printf("\nEnter the adjacency matrix of the graph:-\n\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // Example graph represented as an adjacency matrix
    // int graph[V][V] = {{0, 2, 4, 0, 0, 0},
    //                    {2, 0, 1, 4, 2, 0},
    //                    {4, 1, 0, 0, 3, 0},
    //                    {0, 4, 0, 0, 3, 2},
    //                    {0, 2, 3, 3, 0, 4},
    //                    {0, 0, 0, 2, 4, 0}};

    // int src = 0; // Source vertex
    printf("\n\nEnter Source Vertex: ");
    scanf("%d",&src);
    printf("\nShortest path distances from source vertex %d:\n", src);
    dijkstra(graph, src);

    return 0;
}
