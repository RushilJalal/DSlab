#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return newNode;
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

int main()
{
    Node *X1 = NULL;
    Node *X2 = NULL;
    printf("Enter elements for the first list (X1). Enter -1 to stop:\n");
    int data;
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        Node *newNode = createNode(data);

        if (X1 == NULL)
        {
            X1 = newNode;
        }
        else
        {
            Node *temp = X1;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Enter elements for the second list (X2). Enter -1 to stop:\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        Node *newNode = createNode(data);

        if (X2 == NULL)
        {
            X2 = newNode;
        }
        else
        {
            Node *temp = X2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    if (X1 != NULL && X2 != NULL)
    {
        Node *temp = X1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = X2;
        X2->prev = temp;
    }

    printf("Concatenated List X1: ");
    printList(X1);
    return 0;
}
