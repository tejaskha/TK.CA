#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> findMinMaxDC(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    int mid = (low + high) / 2;
    auto left = findMinMaxDC(arr, low, mid);
    auto right = findMinMaxDC(arr, mid + 1, high);

    int finalMin = min(left.first, right.first);
    int finalMax = max(left.second, right.second);

    return {finalMin, finalMax};
}

int main() {
    vector<int> numbers = {5, 2, 9, 1, 7, 6};
    auto result = findMinMaxDC(numbers, 0, numbers.size() - 1);
    cout << "Divide & Conquer -> Min: " << result.first << ", Max: " << result.second << endl;
    return 0;
}
