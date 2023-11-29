#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

node *root = NULL;

node *createNode(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insert()
{
    int data;
    printf("Enter data");
    scanf("%d", &data);
    node *temp = createNode(data);
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        char dir[10];
        printf("Enter directions(L/R/LRL...): ");
        scanf("%s", dir);
        node *current, *prev;
        prev = NULL;
        current = root;
        int i;
        for (i = 0; i < strlen(dir) && current != NULL; i++)
        {
            prev = current;
            if (dir[i] == 'L')
                current = current->left;
            else
                current = current->right;
        }

        if (current != NULL && i != strlen(dir))
        {
            printf("Insertion not possible");
            free(temp);
            return root;
        }
        if (dir[i - 1] == 'L')
            prev->left = temp;
        else
            prev->right = temp;
    }
    return root;
}

void disp(node *root)
{
    if (root != NULL)
    {
        disp(root->left);
        printf("%d\t", root->data);
        disp(root->right);
    }
}
// take an empty stack and set root of BT as current
// while current != null
// (push current to stack
// set curr = curr->left)
// pop items from stack and print them
// curr = curr->right
void iInorder(node *root)
{
    if (root == NULL)
        return;

    node *stack[20];
    int top = -1;
    node *curr = root;

    while (1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }

        if (top == -1) // Corrected condition for breaking out of the loop
            break;

        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void iPostOrder(node *root)
{
    node *s1[20], *s2[20], *node;
    int top1 = -1, top2 = -1;
    s1[++top1] = root;

    while (top1 > -1)
    {
        node = s1[top1--];
        s2[++top2] = node;

        if (node->left)
            s1[++top1] = node->left;
        if (node->right)
            s1[++top1] = node->right;
    }

    while (top2 > -1)
    {
        node = s2[top2--];
        printf("%d ", node->data);
    }
}

node *parent(node *current, int data, node *prev)
{
    if (current)
    {
        parent(current->left, data, current);
        if (current->data == data)
        {
            printf("%d ", prev->data);
            return prev;
        }
        parent(current->right, data, current);
    }
}

int ancestors(node *root, int ele)
{
    if (root == NULL)
        return 0;
    if (root->data == ele)
        return 1;

    if (ancestors(root->left, ele) || ancestors(root->right, ele))
    {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int depth(node *ptr)
{
    int ldepth, rdepth;
    if (ptr == NULL)
        return 0;
    else
    {
        ldepth = depth(ptr->left);
        rdepth = depth(ptr->right);
        if (ldepth > rdepth)
            return ldepth + 1;
        else
            return rdepth + 1;
    }
}

int isEqual(node *first, node *second)
{
    return (!first && !second) || (first && second && first->data == second->data) &&
                                      isEqual(first->left, second->left) &&
                                      isEqual(first->right, second->right);
}

node *copy(node *ptr)
{
    if (ptr)
    {
        node *temp = malloc(sizeof(node));
        if (ptr->left)
            temp->left = copy(ptr->left);
        if (ptr->right)
            temp->right = copy(ptr->right);
        temp->data = ptr->data;
        return temp;
    }
    return NULL;
}
int main()
{
    printf("How many nodes to create: ");
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        root = insert(root);
        i++;
    }
    printf("Recursive inorder: \n");
    disp(root);
    printf("Iterative Inorder: \n");
    iInorder(root);
    printf("Iterative post order \n");
    iPostOrder(root);
    printf("Parent of 40: \n");
    parent(root, 40, root);
    printf("Ancestors of 40: \n");
    ancestors(root, 40);
    return 0;
}