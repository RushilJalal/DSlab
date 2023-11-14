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
        return;
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

Node *findUnion(Node *list1, Node *list2)
{
    Node *unionList = NULL;

    while (list1 != NULL)
    {
        insertAtEnd(&unionList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        if (!isPresent(unionList, list2->data))
        {
            insertAtEnd(&unionList, list2->data);
        }
        list2 = list2->next;
    }

    return unionList;
}

int isPresent(Node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

Node *findIntersection(Node *list1, Node *list2)
{
    Node *intersectionList = NULL;

    while (list1 != NULL)
    {
        if (isPresent(list2, list1->data))
        {
            insertAtEnd(&intersectionList, list1->data);
        }
        list1 = list1->next;
    }

    return intersectionList;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;

    printf("Enter elements for the first list (list1). Enter -1 to stop:\n");
    int data;
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        insertAtEnd(&list1, data);
    }

    printf("Enter elements for the second list (list2). Enter -1 to stop:\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        insertAtEnd(&list2, data);
    }

    Node *unionList = findUnion(list1, list2);
    printf("Union of the two lists: ");
    printList(unionList);

    Node *intersectionList = findIntersection(list1, list2);
    printf("Intersection of the two lists: ");
    printList(intersectionList);

    return 0;
}
