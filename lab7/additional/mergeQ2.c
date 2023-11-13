#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *mergeSortedLists(Node *X, Node *Y)
{
    Node *Z = NULL;
    Node *currentZ = NULL;

    while (X != NULL && Y != NULL)
    {
        if (X->data <= Y->data)
        {
            if (Z == NULL)
            {
                Z = X;
                currentZ = Z;
            }
            else
            {
                currentZ->next = X;
                currentZ = currentZ->next;
            }

            X = X->next;
        }
        else
        {
            if (Z == NULL)
            {
                Z = Y;
                currentZ = Z;
            }
            else
            {
                currentZ->next = Y;
                currentZ = currentZ->next;
            }

            Y = Y->next;
        }
    }

    if (X != NULL)
    {
        if (Z == NULL)
        {
            Z = X;
        }
        else
        {
            currentZ->next = X;
        }
    }

    if (Y != NULL)
    {
        if (Z == NULL)
        {
            Z = Y;
        }
        else
        {
            currentZ->next = Y;
        }
    }

    return Z;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *X = NULL;
    Node *Y = NULL;
    int sizeX, sizeY;
    printf("Enter size of X");
    scanf("%d", &sizeX);
    for (int i = 0; i < sizeX; i++)
    {
        Node *nodeX = (Node *)malloc(sizeof(Node));
        printf("Enter x data ");
        scanf("%d", &nodeX->data);
        nodeX->next = NULL;

        if (X == NULL)
        {
            X = nodeX;
        }
        else
        {
            Node *tempX = X;
            while (tempX->next != NULL)
            {
                tempX = tempX->next;
            }
            tempX->next = nodeX;
        }
    }

    printf("Enter size of Y");
    scanf("%d", &sizeY);
    for (int i = 0; i < sizeY; i++)
    {
        Node *nodeY = (Node *)malloc(sizeof(Node));
        printf("Enter y data ");
        scanf("%d", &nodeY->data);
        nodeY->next = NULL;

        if (Y == NULL)
        {
            Y = nodeY;
        }
        else
        {
            Node *tempY = Y;
            while (tempY->next != NULL)
            {
                tempY = tempY->next;
            }
            tempY->next = nodeY;
        }
    }

    printf("List X: ");
    printList(X);
    printf("List Y: ");
    printList(Y);

    Node *Z = mergeSortedLists(X, Y);

    printf("Merged List Z: ");
    printList(Z);

    return 0;
}
