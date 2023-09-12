#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursiveSelectionSort(int arr[], int n, int index) {
    if (index == n - 1)
        return;

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    if (minIndex != index)
        swap(&arr[index], &arr[minIndex]);

    recursiveSelectionSort(arr, n, index + 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    recursiveSelectionSort(arr, n, 0);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
