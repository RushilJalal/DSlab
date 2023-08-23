#include <stdio.h>
#define MAXSIZE 20

int arr[MAXSIZE], top[10], bottom[10];

void init(int ns)
{
    //setting boundary index for each sub-stack
    for(int i = 0; i < ns; i++)
    {
        top[i] = bottom[i] = (MAXSIZE/ns) * i -1;
    }
}

void push(int i, int ele)
{
    if (top[i] == bottom[i+1] || top[i] == MAXSIZE - 1)//full condition
        printf("Stack %d is full", i);
    else
    {
        top[i]++;
        arr[top[i]] = ele;
    }
}

int pop(int i)
{
    if (top[i] == bottom[i])//empty condition
        printf("Stack %d is empty", i);
    else
    {
        top[i]--;
        return arr[top[i]];
}
}

void display(int ns)
{
    printf("Displaying each stack: \n");
    for(int i = 0; i < ns; i++)
    {
        printf("%d: ", i);
        for(int j = top[i]; j != bottom[i]; j--)
            printf("%d\t", arr[j]);
        printf("\n");
    }
}

int main()
{
    int ns, i, item;
    printf("Enter number of stacks");
    scanf("%d", &ns);
    init(ns);
    int choice = 0;
     while (choice != 4)
    {
         printf("\n--- Stack Menu ---\n");
         printf("1. Push\n");
         printf("2. Pop\n");
         printf("3. Display\n");
         printf("4. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);

         switch (choice) {
         case 1:
         printf("Enter stack number: ");
         scanf("%d", &i);
         printf("Enter the item to push: ");
         scanf("%d", &item);
         push(i, item);
         break;

         case 2:
         printf("Enter stack number: ");
         scanf("%d", &i);
         printf("Popped item: %d\n", pop(i));
         break;

         case 3:
             display(ns);
         break;

         case 4:
         printf("Exiting...\n");
         return 0;
         default:
         printf("Invalid choice, please try again.\n");
         }
         }
         return 0;
}
