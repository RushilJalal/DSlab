#include <stdio.h>

#define MAX_SIZE 5

struct CQ
{
    int q[MAX_SIZE];
    int front;
    int rear;
    int c;
};

int init(struct CQ *q)
{
    q->front = -1;
    q->rear = -1;
    q->c = 0;
}

int ins(struct CQ *q, int ele)
{
    if (q->c == MAX_SIZE)
    {
        printf("Queue is full \n");
        return -1;
    }
    q->c++;
    q->front++;
    q->q[q->front % MAX_SIZE] = ele;
    return 0;
}

int del(struct CQ *q)
{
    if (q->c == 0)
    {
        printf("Queue is empty \n");
        return -1;
    }
    q->c--;
    q->rear++;
    return q->q[q->rear % MAX_SIZE];
}

int display(struct CQ q)
{
    if (q.c == 0)
    {
        printf("Queue is empty \n");
        return -1;
    }
    printf("The current queue is [");
    int tempc = q.c;
    int i = (q.rear + 1) % MAX_SIZE;
    while (tempc > 0)
    {
        printf("%d, ", q.q[i]);
        tempc--;
        i = (i + 1) % MAX_SIZE;
    }
    printf("] \n");
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
