#include <stdio.h>

#define MAX_SIZE 100
struct Stack
{
    int items[MAX_SIZE];
    int top;
};

void init(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack s)
{
    return s.top == -1;
}

int isFull(struct Stack s)
{
    return s.top == MAX_SIZE - 1;
}

void push(struct Stack *s, int item)
{
    if (isFull(*s))
    {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }

    s->top++;
    s->items[s->top] = item;
}

int pop(struct Stack *s)
{
    if (isEmpty(*s))
    {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }

    int poppedItem = s->items[s->top];
    s->top--;
    return poppedItem;
}

int main()
{
    int item;
    struct Stack stack;
    init(&stack);
    char word[50];
    printf("Enter string to be checked: ");
    scanf("%s", word);
    // push each char in word
    for (int i = 0; word[i] != '\0'; i++)
        push(&stack, word[i]);

    // pop each char in stack and compare with word
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (pop(&stack) != word[i])
        {
            printf("String is not a palindrome.\n");
            return 0;
        }
    }
    printf("String is palindrome\n");
}