#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QueueNode
{
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (!newNode)
            return;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

void enqueue(Queue *queue, Node *data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node *dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        return NULL;
    }

    QueueNode *temp = queue->front;
    Node *data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return data;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Queue queue = {NULL, NULL};
    enqueue(&queue, root);

    while (queue.front != NULL)
    {
        Node *current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            enqueue(&queue, current->left);
        }

        if (current->right != NULL)
        {
            enqueue(&queue, current->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;

    do
    {
        printf("\n1. Insert\n2. Level Order Traversal\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Level Order Traversal: ");
            levelOrderTraversal(root);
            printf("\n");
            break;

        case 0:
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
    return 0;
}
