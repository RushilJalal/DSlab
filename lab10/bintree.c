#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct StackNode
{
    Node *node;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void push(Stack *stack, Node *node)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
        return;
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

Node *pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }

    Node *node = stack->top->node;
    StackNode *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return node;
}

bool isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void inOrderTraversalIterative(Node *root)
{
    Stack stack = {NULL};
    Node *current = root;

    while (current != NULL || !isEmpty(&stack))
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void postOrderTraversalIterative(Node *root)
{
    Stack stack1 = {NULL};
    Stack stack2 = {NULL};
    Node *current = root;

    push(&stack1, current);

    while (!isEmpty(&stack1))
    {
        current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
        {
            push(&stack1, current->left);
        }

        if (current->right != NULL)
        {
            push(&stack1, current->right);
        }
    }

    while (!isEmpty(&stack2))
    {
        current = pop(&stack2);
        printf("%d ", current->data);
    }
}

void preOrderTraversalIterative(Node *root)
{
    Stack stack = {NULL};
    Node *current = root;

    push(&stack, current);

    while (!isEmpty(&stack))
    {
        current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL)
        {
            push(&stack, current->right);
        }

        if (current->left != NULL)
        {
            push(&stack, current->left);
        }
    }
}

Node *findParent(Node *root, int target)
{
    if (root == NULL || (root->left && root->left->data == target) || (root->right && root->right->data == target))
    {
        return root;
    }

    Node *leftResult = findParent(root->left, target);
    if (leftResult != NULL)
    {
        return leftResult;
    }

    return findParent(root->right, target);
}

int findDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

bool printAncestors(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (printAncestors(root->left, target) || printAncestors(root->right, target))
    {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

int countLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-order traversal (Iterative): ");
    inOrderTraversalIterative(root);
    printf("\n");

    printf("Post-order traversal (Iterative): ");
    postOrderTraversalIterative(root);
    printf("\n");

    printf("Pre-order traversal (Iterative): ");
    preOrderTraversalIterative(root);
    printf("\n");

    int targetElement = 5;
    Node *parent = findParent(root, targetElement);
    if (parent != NULL)
    {
        printf("Parent of %d: %d\n", targetElement, parent->data);
    }
    else
    {
        printf("Element not found in the tree.\n");
    }

    printf("Depth of the tree: %d\n", findDepth(root));

    int ancestorElement = 5;
    printf("Ancestors of %d: ", ancestorElement);
    if (!printAncestors(root, ancestorElement))
    {
        printf("Element not found in the tree.\n");
    }
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
