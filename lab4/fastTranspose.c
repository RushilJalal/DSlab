#include <stdio.h>

typedef struct
{
    int row, col, value;
} sparse;

void fastTranspose(sparse original[], sparse transposed[], int rows, int cols, int totalElements)
{
    int colCount[cols];
    int startPos[cols];

    int i, j;

    for (i = 0; i < cols; i++)
    {
        colCount[i] = 0;
    }

    // Count the number of elements in each column(colCount[])
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

    sparse original[totalElements];
    sparse transposed[totalElements];

    printf("Enter the elements of the original matrix (row col value):\n");
    for (int i = 0; i < totalElements; i++)
    {
        scanf("%d %d %d", &original[i].row, &original[i].col, &original[i].value);
    }

    fastTranspose(original, transposed, rows, cols, totalElements);

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < totalElements; i++)
    {
        printf("%d %d %d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }

    return 0;
}
