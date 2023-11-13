#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createLinkedListRecursive(Node *head, int data)
{
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        if (head == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        head->data = data;
        head->next = NULL;
        return head;
    }

    head->next = createLinkedListRecursive(head->next, data);
    return head;
}

void traverseLinkedListRecursive(Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("%d ", head->data);

    traverseLinkedListRecursive(head->next);
}

int main()
{
    Node *head = NULL;

    head = createLinkedListRecursive(head, 1);
    head = createLinkedListRecursive(head, 2);
    head = createLinkedListRecursive(head, 3);

    printf("Linked List: ");
    traverseLinkedListRecursive(head);
    printf("\n");

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
