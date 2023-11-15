#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node
{
    int data;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node *adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; ++i)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void DFS(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex])
        {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int vertices = 6;
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("Depth-First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
