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
        exit(1); // Exit the program on stack overflow
    }
    top++;
    stack[top] = item;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1); // Exit the program on stack underflow
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
    for (int i = 0; i < len; i++)
    {
        char symbol = expression[i];
        if (symbol == ' ')
            continue; // Skip whitespace

        if (isdigit(symbol))
        {
            int num = 0;
            while (isdigit(symbol))
            {
                num = num * 10 + (symbol - '0');
                i++;
                symbol = expression[i];
            }
            i--; // Adjust index after parsing the number
            push(num);
        }
        else if (is_operator(symbol))
        {
            int operand2 = pop();
            int operand1 = pop();
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
                if (operand2 == 0)
                {
                    printf("Division by zero\n");
                    exit(1);
                }
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
    char expression[] = "34+2*";
    int result = evaluate(expression);
    printf("Result = %d\n", result);
    return 0;
}
