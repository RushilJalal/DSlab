#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *copyTree(Node *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    Node *copy = createNode(original->data);
    copy->left = copyTree(original->left);
    copy->right = copyTree(original->right);

    return copy;
}

void printInOrder(Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

int main()
{
    Node *original = createNode(1);
    original->left = createNode(2);
    original->right = createNode(3);
    original->left->left = createNode(4);
    original->left->right = createNode(5);

    Node *copy = copyTree(original);

    printf("Original tree (in-order): ");
    printInOrder(original);
    printf("\n");

    printf("Copied tree (in-order): ");
    printInOrder(copy);
    printf("\n");
    return 0;
}
