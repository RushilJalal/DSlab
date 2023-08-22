#include <stdio.h>

#define STACK_SIZE 100

struct Stack {
    int arr[STACK_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

void convertToBase(int decimalNumber, int base) {
    struct Stack stack;
    initStack(&stack);

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        push(&stack, remainder);
        decimalNumber /= base;
    }

    printf("Converted number in base %d: ", base);
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int decimalNumber, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base: ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base. Please enter a base between 2 and 16.\n");
        return 1;
    }

    convertToBase(decimalNumber, base);

    return 0;
}
