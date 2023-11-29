#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **top, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node **top)
{
    if (isStackEmpty(*top))
    {
        printf("Stack underflow.\n");
        return;
    }

    int data = (*top)->data;
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(Node *top)
{
    if (isStackEmpty(top))
    {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    return top->data;
}

int isStackEmpty(Node *top)
{
    return (top == NULL);
}

void enqueue(Node **front, Node **rear, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(Node **front, Node **rear)
{
    if (isQueueEmpty(*front))
    {
        printf("Queue underflow.\n");
        exit(EXIT_FAILURE);
    }

    int data = (*front)->data;
    Node *temp = *front;

    if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }

    free(temp);
    return data;
}

int peekQueue(Node *front)
{
    if (isQueueEmpty(front))
    {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    return front->data;
}

int isQueueEmpty(Node *front)
{
    return (front == NULL);
}

int main()
{
    Node *stackTop = NULL;
    Node *queueFront = NULL;
    Node *queueRear = NULL;

    push(&stackTop, 1);
    push(&stackTop, 2);
    push(&stackTop, 3);

    printf("Stack: ");
    while (!isStackEmpty(stackTop))
    {
        printf("%d ", pop(&stackTop));
    }
    printf("\n");

    enqueue(&queueFront, &queueRear, 1);
    enqueue(&queueFront, &queueRear, 2);
    enqueue(&queueFront, &queueRear, 3);

    printf("Queue: ");
    while (!isQueueEmpty(queueFront))
    {
        printf("%d ", dequeue(&queueFront, &queueRear));
    }
    printf("\n");

    return 0;
}