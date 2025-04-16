#include <iostream>
using namespace std;

int main()
{
    int n, target;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input the target element to search for
    cout << "Enter the element to search for: ";
    cin >> target;

    // Sequential (Linear) Search
    int found = -1; // To store the index of the target (initialized to -1)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = i; // Target found, store index
            break;     // Exit the loop once the target is found
        }
    }

    // Output the result
    if (found != -1)
    {
        cout << "Element found " << endl;
    }
    else
    {
        cout << "Element not found " << endl;
    }

    return 0;
}