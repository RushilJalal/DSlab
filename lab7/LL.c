#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *start = NULL;
void createList()
{
    if (start == NULL)
    {
        int n;
        printf("Enter number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            Node *newNode;
            Node *current;
            newNode = malloc(sizeof(Node));
            start = newNode;
            current = start;
            printf("Enter start data");
            scanf("%d", &data);
            start->data = data;
            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(Node));
                current->link = newNode;
                printf("Enter data: ");
                scanf("%d", &data);
                newNode->data = data;
                current = current->link;
            }
            current->link = NULL;
            printf("List is created");
        }
    }
    else
        printf("List already created");
}

void traverse()
{
    Node *current;
    if (start == NULL)
        printf("Empty list");
    else
    {
        current = start;
        while (current != NULL)
        {
            printf("Data: %d\n", current->data);
            current = current->link;
        }
    }
}

void insertBefore() // inserts element before specified position
{
    int data, pos;
    Node *current;
    Node *previous;
    Node *nextnode;
    current = malloc(sizeof(Node));
    printf("Enter position to insert before: ");
    scanf("%d", &pos);
    printf("Enter data to enter before element: ");
    scanf("%d", &data);

    current->data = data;
    if(pos == 1) //

}

int main()
{
    createList();
    traverse();
}