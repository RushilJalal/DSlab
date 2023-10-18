#include <stdio.h>

int ternary_search(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternary_search(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternary_search(arr, mid2 + 1, right, key);
        } else {
            return ternary_search(arr, mid1 + 1, mid2 - 1, key);
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = ternary_search(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
