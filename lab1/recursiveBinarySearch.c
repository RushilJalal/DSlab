#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearchRecursive(arr, mid + 1, right, target);
        else
            return binarySearchRecursive(arr, left, mid - 1, target);
    }

    return -1; // Element not found
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
