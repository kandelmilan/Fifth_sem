#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int size, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            low = mid + 1; // Target is in the right half
        else
            high = mid - 1; // Target is in the left half
    }

    return -1; // Target not found
}

int main()
{
    int size, target;

    // Input array size and elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the sorted elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input target element to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Binary Search
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}