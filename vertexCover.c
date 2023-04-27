#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int u, v;
} Edge;

int vertex_cover[100];

void add_edge(int u, int v, Edge edges[], int* edge_count) {
    Edge e = {u, v};
    edges[(*edge_count)++] = e;
}

void print_vertex_cover(int vertex_count) {
    printf("Vertex Cover: ");
    for (int i = 0; i < vertex_count; i++) {
        if (vertex_cover[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void vertex_cover_greedy(int vertex_count, Edge edges[], int edge_count) {
    for (int i = 0; i < edge_count; i++) {
        Edge e = edges[i];
        if (!vertex_cover[e.u] && !vertex_cover[e.v]) {
            vertex_cover[e.u] = 1;
            vertex_cover[e.v] = 1;
        }
    }
}

int main() {
    int i,j,vertex_count,edge_count;

    printf("Enter Number of Verices: ");
    scanf("%d",&vertex_count);
    printf("Enter Number of Edges: ");
    scanf("%d",&edge_count);

    int vertices[vertex_count];
    printf("Enter Vertices: ");
    for(i=0;i<vertex_count;++i){
        scanf("%d",&vertices[i]);
    }

    Edge edges[vertex_count * vertex_count];
    int edge_index = 0,v1,v2;

    printf("\nEnter Edges:-\n");
    for(i=0;i<edge_count;++i){
        printf("\nEdge %d\n:",(i+1));
        printf("Vertex 1: ");
        scanf("%d",&v1);
        printf("Vertex 2: ");
        scanf("%d",&v2);
        add_edge(v1, v2, edges, &edge_index);
    }
    // add_edge(0, 1, edges, &edge_index);
    // add_edge(0, 2, edges, &edge_index);
    // add_edge(1, 2, edges, &edge_index);
    // add_edge(1, 3, edges, &edge_index);
    // add_edge(1, 4, edges, &edge_index);
    // add_edge(2, 4, edges, &edge_index);
    // add_edge(3, 4, edges, &edge_index);
    // add_edge(4, 5, edges, &edge_index);
    // add_edge(5, 6, edges, &edge_index);

    vertex_cover_greedy(vertex_count, edges, edge_count);
    print_vertex_cover(vertex_count);

    return 0;
}
