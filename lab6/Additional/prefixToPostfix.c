#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Structure for the stack
struct Stack
{
    char data[MAX_STACK_SIZE];
    int top;
};

// Initialize a stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(struct Stack *stack)
{
    return (stack->top == MAX_STACK_SIZE - 1);
}

// Push an element onto the stack
void push(struct Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert a prefix expression to postfix
void prefixToPostfix(char *prefix)
{
    int len = strlen(prefix);
    struct Stack stack;
    initialize(&stack);

    // Process the expression from right to left
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isalnum(ch))
        {
            // If it's an operand, push it onto the stack
            push(&stack, ch);
        }
        else if (isOperator(ch))
        {
            // If it's an operator, pop two operands from the stack,
            // concatenate them with the operator, and push the result back onto the stack
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);

            char result[3] = {operand1, operand2, ch};
            push(&stack, result[0]);
            push(&stack, result[1]);
            push(&stack, result[2]);
        }
        else
        {
            // Invalid character
            printf("Invalid character: %c\n", ch);
            exit(1);
        }
    }

    // The postfix expression should be at the top of the stack
    char postfix[MAX_STACK_SIZE];
    int j = 0;
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';

    // Reverse the postfix expression to get the correct order
    strrev(postfix);

    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char prefix[] = "*+AB-CD";
    prefixToPostfix(prefix);
    return 0;
}
// Postfix expression: CD-A+B*