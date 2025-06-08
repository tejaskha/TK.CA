#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> w; // weights array
vector<int> x; // to store the solution

void SumOfSub(int s, int k, int r) {
    x[k] = 1; // include w[k]

    // If current sum + w[k] equals target, print the subset
    if (s + w[k] == m) {
        for (int i = 0; i <= k; ++i) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
    } 
    // Explore left child if it's promising
    else if ((s + w[k] + w[k + 1]) <= m) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    // Explore right child
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;
    w.resize(n);
    x.resize(n, 0);

    int total = 0;
    cout << "Enter elements in non-decreasing order: ";
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        total += w[i];
    }

    cout << "Enter target sum: ";
    cin >> m;

    if (w[0] > m || total < m) {
        cout << "No solution possible." << endl;
    } else {
        cout << "Subsets whose sum is " << m << ":" << endl;
        SumOfSub(0, 0, total);
    }

    return 0;
}
