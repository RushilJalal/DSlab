#include <stdio.h>

// Define a structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} MatrixElement;

// Function to perform slow transpose of a sparse matrix
void slowTranspose(MatrixElement input[], MatrixElement output[], int numRows, int numCols) {
    int outputIndex = 0;

    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            if (input[i].col == j) {
                output[outputIndex].row = input[i].col;
                output[outputIndex].col = input[i].row;
                output[outputIndex].value = input[i].value;
                outputIndex++;
            }
        }
    }
}

int main() {
    // Define the size of the matrix
    int numRows, numCols;

    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &numRows, &numCols);

    // Calculate the maximum possible number of non-zero elements
    int maxNonZero = numRows * numCols;

    // Create an array to store the input matrix
    MatrixElement inputMatrix[maxNonZero];

    // Take input for the matrix
    printf("Enter the elements of the matrix (row, col, value):\n");
    int numNonZero;
    scanf("%d", &numNonZero);

    printf("Enter the elements:\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &inputMatrix[i].row, &inputMatrix[i].col, &inputMatrix[i].value);
    }

    // Create an array to store the transposed matrix
    MatrixElement outputMatrix[maxNonZero];

    // Perform the slow transpose operation
    slowTranspose(inputMatrix, outputMatrix, numRows, numCols);

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("(%d, %d, %d)\n", outputMatrix[i].row, outputMatrix[i].col, outputMatrix[i].value);
    }

    return 0;
}
