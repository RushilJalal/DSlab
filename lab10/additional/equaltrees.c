#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        return;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool areEqualTrees(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    return (root1->data == root2->data) &&
           areEqualTrees(root1->left, root2->left) &&
           areEqualTrees(root1->right, root2->right);
}

int main()
{
    Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (areEqualTrees(root1, root2))
    {
        printf("The two trees are equal.\n");
    }
    else
    {
        printf("The two trees are not equal.\n");
    }
    return 0;
}
