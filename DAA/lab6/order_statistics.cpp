// // write a program to implemenet order statistics(use quick sort)
// ORDER STATISTICS

#include <iostream>
using namespace std;

// Partition function (same as QuickSort)
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low;           // Pointer for smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]); // Place pivot in correct position
    return i;                // Return pivot index
}

// QuickSelect algorithm to find k-th smallest element
int QuickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = Partition(arr, low, high);

        if (pivotIndex == k - 1) // Found the k-th smallest element
            return arr[pivotIndex];

        if (pivotIndex > k - 1) // Search in left subarray
            return QuickSelect(arr, low, pivotIndex - 1, k);

        return QuickSelect(arr, pivotIndex + 1, high, k); // Search in right subarray
    }
    return -1; // Invalid case
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    cout << "Enter the value of k (1 to " << n << "): ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid input! k must be between 1 and " << n << "." << endl;
        return 1;
    }

    int result = QuickSelect(arr, 0, n - 1, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}