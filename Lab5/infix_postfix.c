#include <stdio.h>
#define MAX 20

char arr[MAX]; // operator stack
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

char peek()
{
    return arr[top];
}

char pop()
{
    if (isEmpty())
    {
        printf("Empty stack! Cannot pop");
        return -1;
    }
    char popped = arr[top];
    top--;
    return popped;
}

void push(char opr)
{
    if (isFull())
    {
        printf("Stack is full! Cannot push!");
    }
    else
    {
        top++;
        arr[top] = opr;
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
    case '^':
        return 2;

    case '%':
        return 3;
    }
    return -1;
}

int convert(char *expression)
{
    char output[MAX]; // answer array
    int i, j;
    for (i = 0, j = -1; expression[i] != '\0'; i++)
    {
        if (checkIfOperand(expression[i])) // it is operand(a,b)
            output[++j] = expression[i];   // so it is directly added to the output array

        else if (expression[i] == '(') // encountered open bracket
            push(expression[i]);       // push ( to the operator stack

        else if (expression[i] == ')') // encountered close bracket
        {
            while (!isEmpty() && peek() != '(')
            {
                output[++j] = pop(); // pop all operators until '(' is encountered
            }                        // or the stack is left empty
                                     // stops when '(' is encountered
            // and add the popped operators to the output array

            if (isEmpty() || peek() != '(') // empty stack
                return -1;

            else // pops the bracket
                pop();
        }

        else
        {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                output[++j] = pop();
            push(expression[i]); // Push the operator onto the stack
        }
    }
    while (!isEmpty())
        output[++j] = pop();

    output[++j] = '\0';
    printf("%s", output);
    return 0;
}

int main()
{
    char expression[] = "((x+(y*z))-w)";
    convert(expression);
    return 0;
}
