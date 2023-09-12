#include <stdio.h>
#include <stdlib.h>

// Structure for stack
struct Stack
{
    int data;
    struct Stack *next;
};

// Function to create a new stack node
struct Stack *createNode(int data)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    if (!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack == NULL);
}

// Function to push an element onto the stack
void push(struct Stack **stack, int data)
{
    struct Stack *newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack **stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    struct Stack *temp = *stack;
    *stack = (*stack)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Structure for queue using two stacks
struct Queue
{
    struct Stack *stack1;
    struct Stack *stack2;
};

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data)
{
    push(&queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2))
    {
        printf("Queue is empty\n");
        exit(1);
    }

    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }

    return pop(&queue->stack2);
}

int main()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Dequeue: %d\n", dequeue(queue));

    free(queue);

    return 0;
}
