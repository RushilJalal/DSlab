#include <stdio.h>
int main()
{
    int m, n, A[100][100], B[100][100], C[100][100];
    printf("Enter matrix dimensions: ");
    scanf("%d %d", &m, &n);
    printf("Enter array elements for A: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter array elements for B: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
        }
    }
    printf("Printing max array: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}
