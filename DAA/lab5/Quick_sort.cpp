//LAB-5: Implementation of Divide and Conquer Algorithms (part 2)
//1. Write a program to Implement Quick Sort
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low]; // First element as pivot
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        while (left <= right && arr[right] > pivot) {
            right--;
        }

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    swap(arr[low], arr[right]); // Put pivot in correct position
    return right; // Return the pivot index
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);   // Left subarray
        QuickSort(arr, pivotIndex + 1, high);  // Right subarray
    }
}

// Utility function to print the array
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {24, 9, 29, 14, 19, 27};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    PrintArray(arr, size);

    QuickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    PrintArray(arr, size);

    return 0;
}