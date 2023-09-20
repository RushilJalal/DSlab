#include <stdio.h>  //input (Hello World123aa)
                    //l u d a
#include <string.h> //8 2 3 2
//use 2 stacks fixed char stack and int stack
struct charStack
{
    char data[4];
    int top;
};

typedef struct
{
    int num;
} intStack;

void init1(struct charStack *s)
{
    s->top = -1;
}

void push1(struct charStack *s, int item)
{
    s->top++;
    s->data[s->top] = item;
}

void display1(struct charStack *s)
{
    for (int i = 0; i < 4; i++)
    {
        printf("%c", s->data[i]);
    }
}
int main()
{
    struct charStack *s;
    char input[50];
    printf("Enter string: ");
    gets(input);

    printf("The string is: ");
    puts(input);

    push1(&s, 'l');
    push1(&s, 'u');
    push1(&s, 'd');
    push1(&s, 'a');

    display1(&s);
}