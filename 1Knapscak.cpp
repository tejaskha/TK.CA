#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// M is the capacity of the knapsack
int knapSack(int M, int wt[], int val[], int n) {
    int K[100][100]; // assuming max n and M <= 100

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    // Print the DP Table
    cout << "\nDP Table K (rows: items, cols: capacity):\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            cout << K[i][j] << "\t";
        }
        cout << endl;
    }

    return K[n][M];
}

int main() {
    int val[] = {10, 15, 40};
    int wt[] = {1, 2, 3};
    int M = 6; // capacity
    int n = sizeof(val) / sizeof(val[0]);

    cout << "\nMaximum value in Knapsack = " << knapSack(M, wt, val, n) << endl;
    return 0;
}
