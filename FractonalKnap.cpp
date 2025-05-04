#include <iostream>
#include <algorithm>

using namespace std;

// Structure to store item information
struct Item {
    int profit;
    int weight;
    double ratio;
};

// Comparator function to sort by decreasing ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n = 5;
    int capacity = 12;

    // Given profits and weights
    int profits[] = {12, 1, 2, 1, 4};
    int weights[] = {4, 2, 2, 1, 10};

    // Create array of item
    Item items[5];

    for (int i = 0; i < n; i++) {
        items[i].profit = profits[i];
        items[i].weight = weights[i];
        items[i].ratio = (double)profits[i] / weights[i];
    }

    // Sort items by ratio (greedy criteria)
    sort(items, items + n, compare);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take full item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fractional part
            int remaining = capacity - currentWeight;
            totalProfit += items[i].ratio * remaining;
            break;  // Knapsack full
        }
    }

    cout << "Maximum profit earned = " << totalProfit << endl;

    return 0;
}
