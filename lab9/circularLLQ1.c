#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *last = NULL;
void insert(node *head, int pos, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    if (last == NULL) // if new node is the only node in list
    {
        temp->next = temp;
        last = temp;
    }
    // if pos to be inserted is first(last->next)
    else if(pos == 1)
    {
        temp->next = last->next;
        last->next = temp;
    }
    //if pos to be or not to be inserted at end
    else if(pos==)
}

int size(node *last)
{
    node *current = 
}