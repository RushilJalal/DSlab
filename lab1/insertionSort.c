#include <stdio.h>
//insertion sort
int main() {
    int arr[100], key, n, temp;
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter %d elements of array: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Insertion sorted array: ");
    for (int i= 0; i<n; i++)
        printf("%d ", arr[i]);
}
