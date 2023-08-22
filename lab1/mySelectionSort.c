#include <stdio.h>
// selection sort
int main()
{
    int arr[100], key, n, temp;
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter %d elements of array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Selection sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
