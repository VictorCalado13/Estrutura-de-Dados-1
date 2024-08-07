//Victor Ribeiro Calado - 2313553

//Faça um rastreamento da busca em largura a partir do vértice 1 no grafo definido pelas arestas: 
//0-1 0-2 1-3 1-4 1-5 3-6 3-7 5-8 5-9 7-10 7-11 7-12 9-13 9-14. 
//Observe que a busca em largura percorre o grafo por níveis.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 15

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

void BFS(graph* g, int startVertex) {
    node* queue[MAX_VERTICES];
    int front = 0;
    int back = 0;

    queue[back++] = createNode(startVertex);
    g->visited[startVertex] = 1;

    while (front != back) {
        int currentVertex = queue[front++]->vertex;
        printf("Visitado %d\n", currentVertex);

        node* temp = g->vertices[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (g->visited[adjVertex] == 0) {
                queue[back++] = createNode(adjVertex);
                g->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    graph* g = createGraph();

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 1, 5);
    addEdge(g, 3, 6);
    addEdge(g, 3, 7);
    addEdge(g, 5, 8);
    addEdge(g, 5, 9);
    addEdge(g, 7, 10);
    addEdge(g, 7, 11);
    addEdge(g, 7, 12);
    addEdge(g, 9, 13);
    addEdge(g, 9, 14);

    BFS(g, 1);

    return 0;
}