//Victor Ribeiro Calado - 2313553

//2. Faça uma busca em profundidade no grafo definido pelas arestas: 
//0-1 1-2 1-4 2-3 2-4 2-9 3-4 4-5 4-6 4-7 5-6 7-8 7-9 a partir do vértice 0.
//Exiba o vetor de sequência calculado pela busca. Diga em que ordem os vértices foram descobertos.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct node {
    int vertex;
    struct node* next;
} node;

typedef struct graph {
    node* vertices[MAX_VERTICES];
    int visited[MAX_VERTICES];
} graph;

node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph* createGraph() {
    graph* g = malloc(sizeof(graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

void addEdge(graph* g, int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = g->vertices[src];
    g->vertices[src] = newNode;
}

void DFS(graph* g, int vertex) {
    node* adjList = g->vertices[vertex];
    node* temp = adjList;

    g->visited[vertex] = 1;
    printf("Visitado %d\n", vertex);

    while(temp != NULL) {
        int connectedVertex = temp->vertex;

        if(g->visited[connectedVertex] == 0) {
            DFS(g, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    graph* g = createGraph();

    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    addEdge(g, 2, 9);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    addEdge(g, 4, 6);
    addEdge(g, 4, 7);
    addEdge(g, 5, 6);
    addEdge(g, 7, 8);
    addEdge(g, 7, 9);

    DFS(g, 0);

    return 0;
}