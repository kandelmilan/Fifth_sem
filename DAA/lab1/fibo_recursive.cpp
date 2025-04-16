#include <iostream>
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base case: Fibonacci of 0 is 0, and Fibonacci of 1 is 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {
    int n;
    
    // Input the number of terms in the Fibonacci sequence
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;
    
    cout << "Fibonacci Sequence: ";
    
    // Generate Fibonacci sequence using recursion
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";  // Print each Fibonacci number
    }
    
    cout << endl;

    return 0;
}