#include <stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

node *insertAtEnd(node *head, int data)
{
    node *temp = malloc(sizeof(node));
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    head->next = temp;
    temp->prev = head;
    temp->next = NULL;
}

node *deleteAtEnd(node *head)
{
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current = current->next;
    current->prev->next = NULL; // node before current now points to NULL
    free(current);
    return head;
}

node *insertAtPos(node *head, int data, int pos)
{
    node *current = head;
    node *temp = malloc(sizeof(node));
    temp->next = temp->prev = NULL;
    temp->data = data;
    if (pos == 0)
    {
        head = temp;
        return head;
    }
    for (int i = 1; i < pos; i++)
    {
        current = current->next;
    }
    temp->next = current->next;
    temp->prev = current;
    current->next = temp;
    return head;
}

node *deleteAtPos(node *head, int pos)
{
    node *current = head;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
}

node *insertAfter(node *head, int ele)
{
    node *current = head;
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = ele;
    while (current->data != ele)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
    temp->prev = current;
    temp->next->prev = temp;
    return;
}

node *insertBefore(node *head, int ele)
{
    node *current = head;
    node *temp = malloc(sizeof(node));
    temp->data = ele;
    while (current->data != ele)
    {
        current = current->next;
    }
    current->prev->next = temp;
    temp->prev = current->prev;
    temp->next = current;
    current->prev = temp; // check logic plsssssss
    return;
}

void traverse(node *head)
{
    node *current = head;
    if (current == NULL)
    {
        printf("DLL is empty...");
        return;
    }
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

void reverse(node *head)
{
    
}

// Complete thissssss

int main()
{
    node *head;
    printf("Enter choice: ");
    int choice, data, pos;
    scanf("%d", &choice);
    while (choice != 0)
    {
        printf("1. Insert an element at the rear end of the list");
        printf("2. Delete an element from the rear end of the list");
        printf("3. Insert an element at a given position of the list");
        printf("4. Delete an element from a given position of the list");
        printf("5. Insert an element after another element");
        printf("6. Insert an element before another element");
        printf("7. Traverse the list");
        printf("8. Reverse the list");

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(head, data);
            break;

        case 2:
            deleteAtEnd(head);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPos(head, data, pos);
            break;
        }
    }
    return 0;
}
