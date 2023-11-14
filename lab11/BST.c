#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (!newNode)
            return;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
            {
                printf("%d is found in the tree.\n", data);
            }
            else
            {
                printf("%d is not found in the tree.\n", data);
            }
            break;

        case 4:
            printf("In-order traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 0:
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
