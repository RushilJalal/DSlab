#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct StackNode
{
    TreeNode *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

TreeNode *createNode(char data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
        return;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, TreeNode *data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

TreeNode *pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }
    StackNode *temp = stack->top;
    TreeNode *data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

TreeNode *buildExpressionTree(char postfix[])
{
    Stack *stack = createStack();

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            TreeNode *node = createNode(postfix[i]);
            push(stack, node);
        }
        else
        {
            TreeNode *right = pop(stack);
            TreeNode *left = pop(stack);

            TreeNode *node = createNode(postfix[i]);
            node->right = right;
            node->left = left;

            push(stack, node);
        }
    }

    TreeNode *root = pop(stack);
    free(stack);

    return root;
}

int evaluateExpressionTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (isdigit(root->data))
    {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        return 0;
    }
}

int main()
{
    char postfixExpression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    TreeNode *root = buildExpressionTree(postfixExpression);
    int result = evaluateExpressionTree(root);

    printf("Result: %d\n", result);

    return 0;
}
