#include <stdio.h>

// Function to read a matrix
void readMatrix(int matrix[][10], int rows, int cols)
{
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[][10], int B[][10], int C[][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrices(int A[][10], int B[][10], int C[][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to check if a square matrix is a magic square
int isMagicSquare(int matrix[][10], int size)
{
    int sum = 0;

    // Calculate the sum of the first row
    for (int i = 0; i < size; i++)
    {
        sum += matrix[0][i];
    }

    // Check if rows, columns, and diagonals have the same sum
    for (int i = 0; i < size; i++)
    {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < size; j++)
        {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sum || colSum != sum)
        {
            return 0; // Not a magic square
        }
    }

    // Check the two diagonals
    int diag1Sum = 0, diag2Sum = 0;
    for (int i = 0; i < size; i++)
    {
        diag1Sum += matrix[i][i];
        diag2Sum += matrix[i][size - 1 - i];
    }

    if (diag1Sum != sum || diag2Sum != sum)
    {
        return 0; // Not a magic square
    }

    return 1; // It's a magic square
}

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int rowsA, colsA, rowsB, colsB;

    // Read matrix A
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    readMatrix(A, rowsA, colsA);

    // Read matrix B
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    readMatrix(B, rowsB, colsB);

    // Perform matrix multiplication
    if (colsA == rowsB)
    {
        multiplyMatrices(A, B, C, rowsA, colsA, colsB);
        printf("Matrix A * Matrix B:\n");
        printMatrix(C, rowsA, colsB);
    }
    else
    {
        printf("Matrix multiplication not possible: Number of columns in A must be equal to number of rows in B.\n");
    }

    // Perform matrix addition
    if (rowsA == rowsB && colsA == colsB)
    {
        addMatrices(A, B, C, rowsA, colsA);
        printf("Matrix A + Matrix B:\n");
        printMatrix(C, rowsA, colsA);
    }
    else
    {
        printf("Matrix addition not possible: Both matrices must have the same dimensions.\n");
    }

    // Check if a matrix is a magic square
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);
    int matrix[10][10];
    readMatrix(matrix, size, size);
    if (isMagicSquare(matrix, size))
    {
        printf("The entered matrix is a magic square.\n");
    }
    else
    {
        printf("The entered matrix is not a magic square.\n");
    }

    return 0;
}