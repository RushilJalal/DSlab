#include <stdio.h>
// binary search
//  assume array is sorted
int main()
{
    int arr[100], key, n, found = 0, high, low, mid;
    printf("Enter length of array: ");
    scanf("%d", &n);
    low = 0;
    high = n - 1;
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter search element: ");
    scanf("%d", &key);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (found)
        printf("Element found at %d\n", mid);
    else
        printf("Element not found\n");
    return 0;
}
