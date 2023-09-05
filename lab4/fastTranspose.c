#include <stdio.h>

// Define a structure to represent each element of the sparse matrix
struct Element
{
    int row, col, value;
};

// Function to perform fast transpose of a sparse matrix
void fastTranspose(struct Element original[], struct Element transposed[], int rows, int cols, int totalElements)
{
    // Initialize an array to store the count of elements in each column of the original matrix
    int colCount[cols];
    int startPos[cols];

    // Initialize count and index variables
    int i, j;

    // Initialize colCount array to 0
    for (i = 0; i < cols; i++)
    {
        colCount[i] = 0;
    }

    // Count the number of elements in each column
    for (i = 0; i < totalElements; i++)
    {
        colCount[original[i].col]++;
    }

    // Calculate the starting position of each column in the transposed matrix
    startPos[0] = 0;
    for (i = 1; i < cols; i++)
    {
        startPos[i] = startPos[i - 1] + colCount[i - 1];
    }

    // Perform the fast transpose
    for (i = 0; i < totalElements; i++)
    {
        j = startPos[original[i].col];
        transposed[j].row = original[i].col;
        transposed[j].col = original[i].row;
        transposed[j].value = original[i].value;
        startPos[original[i].col]++;
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int totalElements;
    printf("Enter the total number of non-zero elements: ");
    scanf("%d", &totalElements);

    // Create arrays to store the original and transposed matrices
    struct Element original[totalElements];
    struct Element transposed[totalElements];

    // Input the elements of the original matrix
    printf("Enter the elements of the original matrix (row col value):\n");
    for (int i = 0; i < totalElements; i++)
    {
        scanf("%d %d %d", &original[i].row, &original[i].col, &original[i].value);
    }

    // Perform the fast transpose
    fastTranspose(original, transposed, rows, cols, totalElements);

    // Display the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < totalElements; i++)
    {
        printf("%d %d %d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }

    return 0;
}
