#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int maxSize;
} Stack;

Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(maxSize * sizeof(int));
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->maxSize - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

typedef struct {
    Stack* inbox;
    Stack* outbox;
} Queue;

Queue* createQueue(int maxSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->inbox = createStack(maxSize);
    queue->outbox = createStack(maxSize);
    return queue;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue->inbox)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    push(queue->inbox, value);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->inbox) && isEmpty(queue->outbox)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    if (isEmpty(queue->outbox)) {
        while (!isEmpty(queue->inbox)) {
            int value = pop(queue->inbox);
            push(queue->outbox, value);
        }
    }

    return pop(queue->outbox);
}

int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    return 0;
}
