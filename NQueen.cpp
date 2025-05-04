#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int x[100]; // to store column positions of queens
int solutionCount = 0;

// Function to check if kth queen can be placed in column i
bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; // Same column or same diagonal
        }
    }
    return true;
}

// Recursive function to solve N-Queens
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                // Found a valid solution
                solutionCount++;
                cout << "Solution " << solutionCount << ": ";
                for (int j = 1; j <= n; j++) {
                    cout << "(" << j << "," << x[j] << ") ";
                }
                cout << endl;
            } else {
                NQueens(k + 1, n); // Recurse for next queen
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter value of N (number of queens): ";
    cin >> n;

    NQueens(1, n);

    cout << "Total number of solutions: " << solutionCount << endl;
    return 0;
}
