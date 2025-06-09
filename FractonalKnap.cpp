#include <iostream>
using namespace std;

void fractionalKnapsack(int m, int n, float p[], float w[], float x[]) {
    float U = m; // Remaining capacity
    int i;

    // Initialize solution vector
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Fill knapsack
    for (i = 0; i < n; i++) {
        if (w[i] > U) {
            break;
        }
        x[i] = 1.0;
        U = U - w[i];
    }

    // Take fraction of next item
    if (i < n) {
        x[i] = U / w[i];
    }
}

int main() {
    int n = 3;          // Number of items
    int m = 50;         // Knapsack capacity

    float p[10] = {60, 100, 120};   // Profits
    float w[10] = {10, 20, 30};     // Weights
    float x[10];                    // Solution vector

    // NOTE: The items must be sorted by p[i]/w[i] in descending order already

    fractionalKnapsack(m, n, p, w, x);

    cout << "Solution vector (fractions of items taken):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
