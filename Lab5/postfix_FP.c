#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char stack[MAX][MAX]; // String stack
int top = -1;

void push(char *item)
{
    if (isFull())
        printf("Stack Overflow \n");
    else
    {
        top++;
        strcpy(stack[top], item);
    }
}

int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

int isOperator(char sym)
{
    return (sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '^');
}

char *pop()
{
    if (isEmpty())
        exit(0);
    return stack[top--];
}

int isOperand(char sym)
{
    return (sym >= 'a' && sym <= 'z');
}

int main()
{
    char postfix[MAX], temp[2], op[2] = {'(', '\0'}, cl[2] = {')', '\0'}; // open/close arrays
    int i = 0, j = 0;
    printf("Enter a postfix expression: ");
    gets(postfix);
    while (postfix[i] != '\0')
    {
        char exp[MAX] = {'\0'}, op1[MAX] = {'\0'}, op2[MAX] = {'\0'};
        temp[0] = postfix[i];
        temp[1] = '\0';
        if (isOperand(temp[0]))
            push(temp);
        else if (isOperator(temp[0]))
        { // to push in the form (operand1 operator operand2)
            strcpy(op2, pop());
            strcpy(op1, pop());
            strcat(exp, op);
            strcat(exp, op1);
            strcat(exp, temp);
            strcat(exp, op2);
            strcat(exp, cl);
            push(exp);
        }
        else
        {
            printf("Invalid Arithmetic expression!\n");
            exit(0);
        }
        i++;
    }
    printf("The FP infix expression is: ");
    puts(stack[0]);
}
// Enter a postfix expression: ab+c-
// The FP infix expression is: ((a+b)-c)