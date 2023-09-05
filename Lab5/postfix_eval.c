#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    top++;
    stack[top] = item;
}
int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}

int isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int evaluate(char *expression)
{
    int i = 0;
    char symbol = expression[i];
    int operand1, operand2, result, val;
    while (symbol != '\0')
    {
        if (symbol >= '0' && symbol <= '9') // number, operand
        {
            int num = symbol - '0'; // converting char to int
            push(num);
        }
        else if (checkIfOperand(symbol))
        {
            printf("Enter value of % c", symbol);
            scanf("%d", &val);
            push(val);
        }
        else if (isOperator(symbol))
        {
            operand2 = pop();
            operand1 = pop();
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
        i++;
        symbol = expression[i];
    }
    result = pop();
    return result;
}

int main()
{
    char expression[] = "abc+*d-";
    int result = evaluate(expression);
    printf("Result= %d\n", result);
    return 0;
}