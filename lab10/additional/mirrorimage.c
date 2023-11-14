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
        return;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int areMirrorTrees(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    return (root1->data == root2->data) &&
           areMirrorTrees(root1->left, root2->right) &&
           areMirrorTrees(root1->right, root2->left);
}

int main()
{
    Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    Node *root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    if (areMirrorTrees(root1, root2))
    {
        printf("The two trees are mirrors.\n");
    }
    else
    {
        printf("The two trees are not mirrors.\n");
    }

    return 0;
}
