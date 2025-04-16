#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (num < 0)
        cout << "Factorial is not defined for negative numbers!" << endl;
    else
        cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    return 0;
}