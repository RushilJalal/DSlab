#include <stdio.h>

#define MAX_SIZE 5

struct CQ
{
    int q[MAX_SIZE];
    int front;
    int rear;
};

int init(struct CQ *q)
{
    q->front = 0;
    q->rear = 0;
}

int ins(struct CQ *q, int ele)
{
    if ((q->front + 1) % MAX_SIZE == q->rear)
    {
        printf("Queue is full \n");
        return -1;
    }
    q->front++;
    q->q[q->front % MAX_SIZE] = ele;
    return 0;
}

int del(struct CQ *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty \n");
        return -1;
    }
    q->rear++;
    return q->q[q->rear % MAX_SIZE];
}

int display(struct CQ q)
{
    if (q.rear == q.front)
    {
        printf("Queue is empty \n");
        return -1;
    }
    printf("The current queue is [");
    int i;

    for (i = q.rear + 1; i != q.front; i++)
    {
        printf("%d, ", q.q[i % MAX_SIZE]);
    }
    printf("%d] \n", q.q[i % MAX_SIZE]);
    return 0;
}

int main()
{
    struct CQ q;
    init(&q);
    int choice;
    while (1)
    {
        printf("1. Insert an element \n");
        printf("2. Remove front \n");
        printf("3. Display queue \n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Element to be inserted: ");
            int ele;
            scanf("%d", &ele);
            ins(&q, ele);
            break;
        case 2:
            printf("%d\n", del(&q));
            break;
        case 3:
            display(q);
            break;
        default:
            return 0;
        }
    }
    return 0;
}
