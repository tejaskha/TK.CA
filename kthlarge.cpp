#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array such that elements greater than pivot are on the left
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int pIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] >= pivot) { // for kth largest
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[right]);
    return pIndex;
}

// Quickselect function
int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1; // error case
}

int findKthLargest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, k - 1); // index = k-1 for kth largest
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = findKthLargest(arr, size, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
