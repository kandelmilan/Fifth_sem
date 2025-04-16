//write a program to implemenet order statistics(use quick sort)
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (same as in QuickSort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

// QuickSelect function to find k-th smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(arr, low, high);

        if (index - low == k - 1)
            return arr[index];
        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);

        return quickSelect(arr, index + 1, high, k - index + low - 1);
    }

    return -1; // if k is out of range
}

int main() {
    int n, k;

    // Get array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Get value of k
    printf("Enter the value of k (to find k-th smallest element): ");
    scanf("%d", &k);

    // Call quickSelect
    int result = quickSelect(arr, 0, n - 1, k);

    if (result != -1)
        printf("The %d-th smallest element is %d\n", k, result);
    else
        printf("Invalid input! k should be between 1 and %d\n", n);

    return 0;
}

