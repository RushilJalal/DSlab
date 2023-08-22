#include <stdio.h>
//bubble sort
int main() {
    int arr[100], key, n, temp;
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter %d elements of array: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }
    for (int i = 0; i< n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
    printf("Bubble sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
