// write a program to implement merge sort

#include <stdio.h>

// Function to merge two parts of the array
void merge(int arr[], int start, int mid, int end) {
    int i, j, k;
    
    // Sizes of two parts
    int size1 = mid - start + 1;
    int size2 = end - mid;

    // Create temporary arrays
    int left[size1], right[size2];

    // Copy data to temporary arrays
    for (i = 0; i < size1; i++)
        left[i] = arr[start + i];
    for (j = 0; j < size2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the two arrays back into arr[]
    i = 0; j = 0; k = start;
    while (i < size1 && j < size2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left[], if any
    while (i < size1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements from right[], if any
    while (j < size2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to divide the array and sort it
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        // Find the middle point
        int mid = (start + end) / 2;

        // Recursively divide and sort both halves
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves
        merge(arr, start, mid, end);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    // Call merge sort
    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
