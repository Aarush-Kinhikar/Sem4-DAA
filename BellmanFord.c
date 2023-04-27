#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to print the distance array
void printDistances(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Bellman-Ford algorithm function
void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Initialize distances from source to all vertices as infinity
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    // Distance from source to itself is 0
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    printDistances(dist, V);
}

int main() {
    // Example graph
    int V,E,src,i;
    printf("Enter Number of Vertices: ");
    scanf("%d",&V);
    printf("Enter Number of Edges: ");
    scanf("%d",&E);
    // V = 5; // Number of vertices
    // E = 8; // Number of edges
    struct Graph* graph = createGraph(V, E);
    printf("\nEnter Source, Destination and Weight for each edge:-\n");
    for (i=0;i<E;i++){
        printf("\nEdge %d\n",(i+1));
        printf("Source: ");
        scanf("%d",&graph->edges[i].src);
        printf("Destination: ");
        scanf("%d",&graph->edges[i].dest);
        printf("Weight: ");
        scanf("%d",&graph->edges[i].weight);
    }
    // graph->edges[0].src = 0;
    // graph->edges[0].dest = 1;
    // graph->edges[0].weight = -1;
    // graph->edges[1].src = 0;
    // graph->edges[1].dest = 2;
    // graph->edges[1].weight = 4;
    // graph->edges[2].src = 1;
    // graph->edges[2].dest = 2;
    // graph->edges[2].weight = 3;
    // graph->edges[3].src = 1;
    // graph->edges[3].dest = 3;
    // graph->edges[3].weight = 2;
    // graph->edges[4].src = 1;
    // graph->edges[4].dest = 4;
    // graph->edges[4].weight = 2;
    // graph->edges[5].src = 3;
    // graph->edges[5].dest = 1;
    // graph->edges[5].weight = 1;
    // graph->edges[6].src = 3;
    // graph->edges[6].dest = 4;
    // graph->edges[6].weight = 5;
    // graph->edges[7].src = 4;
    // graph->edges[7].dest = 3;
    // graph->edges[7].weight = -3;
    printf("\n\nEnter Source Vertex: ");
    scanf("%d",&src);
    //src = 0; // Source vertex
    printf("Bellman-Ford Algorithm:\n");
    printf("Source vertex: %d\n", src);
    bellmanFord(graph, src);
return 0;
}
