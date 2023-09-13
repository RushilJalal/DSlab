#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = item;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item = stack[top];
    top--;
    return item;
}

int is_operator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int evaluate(char *expression)
{
    int len = strlen(expression);
    for (int i = len - 1; i >= 0; i--) // Start from the end of the expression 
    {
        char symbol = expression[i];
        if (symbol == ' ')
            continue;

        if (isdigit(symbol))
        {
            push(symbol - '0'); // Converts character to an integer and push it
        }
        else if (is_operator(symbol))
        {
            int operand1 = pop();
            int operand2 = pop();
            int result;

            switch (symbol)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char expression[50];
    printf("Enter prefix expression: ");
    gets(expression);
    int result = evaluate(expression);
    printf("Result = %d\n", result);
    return 0;
}
//input:+3*42
//output: result = 11 