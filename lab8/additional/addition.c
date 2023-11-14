#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int digit;
    struct Node *next;
} Node;

Node *createNode(int digit)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return;
    }
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int digit)
{
    Node *newNode = createNode(digit);
    newNode->next = head;
    return newNode;
}

Node *addNumbers(Node *num1, Node *num2)
{
    Node *result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0)
    {
        int digit1 = (num1 != NULL) ? num1->digit : 0;
        int digit2 = (num2 != NULL) ? num2->digit : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        result = insertAtBeginning(result, sum % 10);

        if (num1 != NULL)
        {
            num1 = num1->next;
        }
        if (num2 != NULL)
        {
            num2 = num2->next;
        }
    }

    return result;
}

void printNumber(Node *head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->digit);
        head = head->next;
    }
}

int main()
{
    Node *num1 = NULL;
    Node *num2 = NULL;

    printf("Enter the first number (enter -1 to stop): ");
    int digit;
    while (1)
    {
        scanf("%d", &digit);
        if (digit == -1)
        {
            break;
        }
        num1 = insertAtBeginning(num1, digit);
    }

    printf("Enter the second number (enter -1 to stop): ");
    while (1)
    {
        scanf("%d", &digit);
        if (digit == -1)
        {
            break;
        }
        num2 = insertAtBeginning(num2, digit);
    }

    Node *result = addNumbers(num1, num2);
    printf("Sum of the two numbers: ");
    printNumber(result);
    printf("\n");

    return 0;
}
