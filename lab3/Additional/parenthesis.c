#include <stdio.h>

#define MAX 100

int areParenthesesMatching(const char *expression)
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; expression[i] != '\0' && expression[i] != '\n'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            if (top == MAX - 1)
            {
                return 0;
            }
            stack[++top] = expression[i];
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (top == -1)
            {
                return 0; // Unmatched closing parenthesis
            }
            if ((expression[i] == ')' && stack[top] != '(') ||
                (expression[i] == '}' && stack[top] != '{') ||
                (expression[i] == ']' && stack[top] != '['))
            {
                return 0; // Mismatched parentheses
            }
            top--;
        }
    }

    return (top == -1) ? 1 : 0; // Check if stack is empty
}

int main()
{
    char expression[MAX];
    printf("Enter an expression (up to %d characters): ", MAX - 1);

    int c;
    int i = 0;
    while (i < MAX - 1)
    {
        c = getchar();
        if (c == '\n')
        {
            expression[i] = '\0';
            break;
        }
        expression[i++] = (char)c;
    }

    if (areParenthesesMatching(expression))
    {
        printf("Parentheses are matching.\n");
    }
    else
    {
        printf("Parentheses are not matching.\n");
    }

    return 0;
}
