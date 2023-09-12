#include <stdio.h>

// Function to multiply two numbers using repeated addition recursively
int multiply(int num1, int num2)
{
    // Base case: if num2 is 0, the result is 0
    if (num2 == 0)
    {
        return 0;
    }
    // Recursive case: Add num1 to the result of multiplying (num1, num2-1)
    return num1 + multiply(num1, num2 - 1);
}

int main()
{
    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = multiply(num1, num2);

    printf("Result of %d * %d is %d\n", num1, num2, result);

    return 0;
}
