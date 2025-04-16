#include <iostream>
using namespace std;

int main()
{
    int n, first = 0, second = 1, temp;

    // Read the number of terms
    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;

    // Print the first two terms
    cout << "Fibonacci Sequence: " << first << " " << second << " ";

    // Generate the rest of the sequence
    for (int i = 3; i <= n; i++)
    {
        temp = first + second;
        cout << temp << " ";
        first = second;
        second = temp;
    }

    return 0;
}