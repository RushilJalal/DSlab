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

struct QueueNode
{
    int data;
    struct QueueNode *next;
};

struct Queue
{
    struct QueueNode *front, *rear;
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

struct QueueNode *createQueueNode(int data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data)
{
    struct QueueNode *newNode = createQueueNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
        return -1; // Queue is empty
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

void BFS(struct Graph *graph, int startVertex)
{
    struct Queue *queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != NULL)
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(queue);
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

    printf("Breadth-First Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}
