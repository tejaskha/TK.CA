#include <iostream>
#include <algorithm>

using namespace std;

// Structure to store weight and profit of each item
struct Item {
    int weight;
    int profit;
};

// Function to compare two items based on profit/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

// Function to get the maximum value in a fractional knapsack
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by descending profit/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].profit;
        } else {
            // Take the fraction of the remaining item
            totalValue += (double)items[i].profit * capacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[100]; // Assume a max of 100 items

    cout << "Enter weight and profit for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(capacity, items, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
