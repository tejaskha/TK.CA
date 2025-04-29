#include <iostream>
using namespace std;

void findMinMaxDC(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        min = max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int min1, max1, min2, max2;

    findMinMaxDC(arr, low, mid, min1, max1);
    findMinMaxDC(arr, mid + 1, high, min2, max2);

    min = (min1 < min2) ? min1 : min2;
    max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMaxDC(arr, 0, n - 1, min, max);
    cout << "Divide & Conquer -> Min: " << min << ", Max: " << max << endl;

    return 0;
}
