#include <iostream>
using namespace std;

int main() {
    int n, fact = 1;

    // Read the number from user
    cout << "Enter a number: ";
    cin >> n;

    // Calculate factorial
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    // Print the result
    cout << "Factorial of " << n << " is: " << fact << endl;

    return 0;
}