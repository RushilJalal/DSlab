#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode->prev = head;
    }
    else
    {
        Node *last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    return head;
}

Node *deleteElement(Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    Node *current = head;
    Node *temp = NULL;

    while (current->data != key)
    {
        current = current->next;

        if (current == head)
        {
            printf("Element not found in the list.\n");
            return head;
        }
    }

    if (current->next == head && current->prev == head)
    {
        free(current);
        head = NULL;
    }
    else
    {
        temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head)
        {
            head = current->next;
        }

        free(temp);
    }

    printf("Element %d deleted from the list.\n", key);
    return head;
}

void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main()
{
    Node *head = NULL;
    int choice, data, key;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert an element into the doubly linked circular list\n");
        printf("2. Delete an element from the doubly linked circular list\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;

        case 2:
            if (head == NULL)
            {
                printf("List is empty. Deletion not possible.\n");
                break;
            }
            printf("Enter the element to be deleted: ");
            scanf("%d", &key);
            head = deleteElement(head, key);
            break;

        case 3:
            printf("Doubly Linked Circular List: ");
            displayList(head);
            break;

        case 4:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
