#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *mergeLists(Node *list1, Node *list2)
{
    Node *list3 = NULL;
    Node *currentList1 = list1;
    Node *currentList2 = list2;
    Node *currentList3 = NULL;

    while (currentList1 != NULL && currentList2 != NULL)
    {
        if (list3 == NULL)
        {
            list3 = currentList1;
            currentList3 = list3;
        }
        else
        {
            currentList3->next = currentList1;
            currentList3 = currentList3->next;
        }

        currentList1 = currentList1->next;

        currentList3->next = currentList2;
        currentList3 = currentList3->next;
        currentList2 = currentList2->next;
    }

    while (currentList2 != NULL)
    {
        currentList3->next = currentList2;
        currentList3 = currentList3->next;
        currentList2 = currentList2->next;
    }

    return list3;
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

void freeList(Node *head)
{
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

Node *createList()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main()
{
    Node *list1 = createList();
    Node *list2 = createList();

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    Node *list3 = mergeLists(list1, list2);

    printf("Merged List 3: ");
    printList(list3);

    freeList(list3);

    return 0;
}
