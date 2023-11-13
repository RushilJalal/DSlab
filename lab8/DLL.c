#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

void insertAtEnd(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        printf("Empty DLL when trying to insert at end\n");
        return;
    }

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
    temp->prev = current;
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Empty DLL when trying to delete at end\n");
        return;
    }

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    else
    {
        // If there is only one element in the list
        head = NULL;
    }

    free(current);
}

node *insertAtPos(int data, int pos)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (pos == 0)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    node *current = head;
    for (int i = 1; i < pos && current != NULL; i++)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        temp->next = current->next;
        temp->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = temp;
        }
        current->next = temp;
    }

    return head;
}

void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("Empty DLL when trying to delete at position\n");
        return;
    }

    node *current = head;
    for (int i = 0; i < pos && current != NULL; i++)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        else
        {
            // If deleting the first element
            head = current->next;
        }

        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }

        free(current);
    }
}

node *insertAfter(int ele, int eleAfter)
{
    node *current = head;
    node *temp = malloc(sizeof(node));
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;

    while (current != NULL && current->data != eleAfter)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        temp->next = current->next;
        temp->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = temp;
        }
        current->next = temp;
    }

    return head;
}

node *insertBefore(int ele, int eleBefore)
{
    node *current = head;
    node *temp = malloc(sizeof(node));
    temp->data = ele;
    temp->next = NULL;
    temp->prev = NULL;

    while (current != NULL && current->data != eleBefore)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        temp->prev = current->prev;
        temp->next = current;
        if (current->prev != NULL)
        {
            current->prev->next = temp;
        }
        current->prev = temp;
    }

    return head;
}

void traverse()
{
    node *current = head;
    if (current == NULL)
    {
        printf("DLL is empty...can't traverse\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse()
{
    node *current = head;
    node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    int choice = 1, data, pos, ele1, ele2;
    while (choice != 0)
    {
        printf("1. Insert an element at the rear end of the list\n");
        printf("2. Delete an element from the rear end of the list\n");
        printf("3. Insert an element at a given position of the list\n");
        printf("4. Delete an element from a given position of the list\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 2:
            deleteAtEnd();
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPos(data, pos);
            break;

        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;

        case 5:
            printf("Enter element to be inserted: ");
            scanf("%d", &ele1);
            printf("Enter element after which ele1 is inserted: ");
            scanf("%d", &ele2);
            insertAfter(ele1, ele2);
            break;

        case 6:
            printf("Enter element to be inserted: ");
            scanf("%d", &ele1);
            printf("Enter element to be inserted before of: ");
            scanf("%d", &ele2);
            insertBefore(ele1, ele2);
            break;

        case 7:
            traverse();
            break;

        case 8:
            reverse();
            break;

        case 0:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    // Free allocated memory before exiting
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}