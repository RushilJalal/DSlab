include <stdio.h>
//linear search
int main() {
    int arr[100], key, n, found = 0;
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter %d elements of array: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            printf("Element %d found at index %d", key, i);
            break;
        }
    }
    if (found == 0)
    {
        printf("Not found");
    }
    return 0;
}

