#include <stdio.h>
#define MAX 20

char arr[MAX];//operator stack
int top = -1;

int isEmpty()
{
    return top==-1;
}

int isFull()
{
    return top = MAX - 1;
}

char peek()
{
    return arr[top];
}

char pop()
{
    if(isEmpty())
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
    if(isFull())
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
    return (ch>='a' && ch<='z');
}

int precedence(char ch)
{
    switch(ch)
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

int convert(char *statement)//input statement to be converted
//replace var name statement with expression
{
    char output[MAX];//answer array
    int i,j;
    for(i = 0, j = -1; statement[i] != '\0';i++)
    {
        if(checkIfOperand(statement[i]))//it is operand(number)
            output[++j] = statement[i];// so it is directly added to output array

        else if(statement[i] == '(')//encountered open bracket
            push(statement[i]);//push ( to operator stack

        else if(statement[i] == ')')//encountered close bracket
        {
            while(!isEmpty() && peek() != '(')
            {
                output[++j] = pop();//pop all operators until ( is encountered
            }//or stack is left empty
            //and add the popped operators to output array

            if(!isEmpty() && peek() != '(')// non empty stack and peek gives required open bracket
                return -1;

            else//doubt
                pop();//pop the operator
        }

        else
        {
            while(!isEmpty() && precedence(statement[i]) <= precedence(peek()))
                output[++j] = pop();
            push(statement[i]);
        }
    }
    while(!isEmpty())
        output[++j] = pop();

    output[++j] = '\0';
    printf("%s", output);
}

int main()
{
    char statement[] = "((x+(y*z))-w)";
    convert(statement);
    return 0;
}