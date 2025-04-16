//write a program to implement fractional knapsack problem 
#include <iostream>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item {
    double value, weight;
};

// Comparator to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

// Function to perform Fractional Knapsack
double FractionalKnapsack(double W, Item items[], int n) {
    // Sort items by value-to-weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W == 0)
            break;

        double takeAmount = min(items[i].weight, W);
        totalValue += takeAmount * (items[i].value / items[i].weight);
        W -= takeAmount;
    }
    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter value and weight for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " ( weight value ): ";
        cin >> items[i].weight >> items[i].value;
    }

    double W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    double maxValue = FractionalKnapsack(W, items, n);

    cout << "Maximum total value in knapsack: " << maxValue << endl;

    return 0;
}
