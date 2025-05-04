#include <iostream>
using namespace std;

void subsetSum(int w[], int n, int index, int currentSum, int target, int subset[]) {
    if (currentSum == target) {
        cout << "Subset found: ";
        for (int i = 0; i < index; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index == n || currentSum > target) {
        return;
    }

    // Include the current element
    subset[index] = w[index];
    subsetSum(w, n, index + 1, currentSum + w[index], target, subset);

    // Exclude the current element
    subsetSum(w, n, index + 1, currentSum, target, subset);
}

int main() {
    int w[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(w) / sizeof(w[0]);
    int target = 35;
    int subset[100];  // assuming max 100 elements

    cout << "Subsets with sum " << target << ":\n";
    subsetSum(w, n, 0, 0, target, subset);

    return 0;
}
