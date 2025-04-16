 #include <iostream>
using namespace std;

// Recursive function to calculate sum of first n natural numbers
int sum(int n) {
    // Base case: If n is 0, the sum is 0
    if (n == 0)
        return 0;
    // Recursive case: sum of n is n + sum of (n-1)
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Please enter a positive integer.";
    } else {
        cout << "The sum of the first " << n << " natural numbers is: " << sum(n) << endl;
    }
    
    return 0;
}