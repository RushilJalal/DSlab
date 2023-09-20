#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

char stk[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return (top == MAX - 1);
}

char peek()
{
    return stk[top];
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack empty!");
        return;
    }
    char ch = stk[top];
    top--;
    return (ch);
}

void push(char oper)
{
    if (isFull())
        printf("Stack Full!!!!");
    else
    {
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
    case '%':
        return 3;
    }
    return -1;
}

void convertInfixToPrefix(char *expression)
{
    int i, j;
    char output[20];
    for (i = 0; expression[i] != '\0'; i++) // traversing backwards
        ;
    i = i - 1;
    for (j = -1; i >= 0; i--)
    {
        if (checkIfOperand(expression[i]))
            output[++j] = expression[i];
        else if (expression[i] == ')')
            push(expression[i]);
        else if (expression[i] == '(')
        {
            while (!isEmpty() && peek() != ')')
                output[++j] = pop();
            if (!isEmpty() && peek() != ')')
            {
                printf("Mismatched parentheses.\n");
                return;
            }
            else
                pop();
        }
        else
        {
            while (!isEmpty() && precedence(expression[i]) < precedence(peek()))
                output[++j] = pop();
            push(expression[i]);
        }
    }
    while (!isEmpty())
    {
        output[++j] = pop();
    }
    output[++j] = '\0';
    strrev(output);
    puts(output);
}

int main()
{
    char expression[50];
    printf("Enter infix expression: ");
    gets(expression);
    convertInfixToPrefix(expression);
    return 0;
}
// Enter infix expression: a+b-c
//-+abc
