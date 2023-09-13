#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack
{
    char data[MAX];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

int isFull(struct Stack *stack)
{
    return (stack->top == MAX - 1);
}

void push(struct Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToPostfix(char *prefix)
{
    int len = strlen(prefix);
    struct Stack stack;
    initialize(&stack);

    for (int i = len - 1; i >= 0; i--) // traverse right to left
    {
        char ch = prefix[i];

        if (isalnum(ch)) // checks alphabet and number
        {
            push(&stack, ch);
        }
        else if (isOperator(ch))
        {
            // If operator encountered, pop two operands from the stack,
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
    char postfix[MAX];
    int j = 0;
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';

    // Reverse the postfix expression to get the correct order
    strrev(postfix);

    puts(postfix);
}

int main()
{
    char prefix[] = "*+AB-CD";
    prefixToPostfix(prefix);
    return 0;
}
// Postfix expression: CD-A+B*