#include <iostream>
using namespace std;

// Binary Search function using Divide and Conquer approach
int binarySearch(int numbers[], int l, int r, int x) {
    if (l <= r) {
        int mid = l + (r - l) / 2;

        // If element is present at the middle itself
        if (numbers[mid] == x)
            return mid;

        // If element is smaller than mid, then search in the left subarray
        if (numbers[mid] > x)
            return binarySearch(numbers, l, mid - 1, x);

        // Else the element can only be in right subarray
        return binarySearch(numbers, mid + 1, r, x);
    }

    // Element is not present in array
    return -1;
}

int main() {
    int numbers[] = {11, 23, 31, 42, 47, 55, 63, 70, 88}; // Sorted array
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int x = 63;

    int result = binarySearch(numbers, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int numbers[] = {11, 23, 31, 42, 47, 55, 63, 70, 88}; // Sorted array
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int x = 63;

    int l = 0, r = n - 1;
    int mid;
    bool found = false;

    while (l <= r) {
        mid = l + (r - l) / 2;

        if (numbers[mid] == x) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        }
        else if (numbers[mid] > x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
