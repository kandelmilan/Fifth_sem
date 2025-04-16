#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; 
        int j = i - 1;    

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{


    int n;
    cout << "Enter the number of element in array ";
    cin >> n;
    int arr[n];
    cout << "Enter the element of the array ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    InsertionSort(arr, n);


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
