#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int i = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
        i++;
    }
    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }
    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}
int main()
{
    int arrr[] = {1, 6, 6, 7, 3, 2, 1, 6};
    int low = 0;
    int high = (sizeof(arrr) / sizeof(arrr[0])) - 1;
    MergeSort(arrr, low, high);
    for (int i = 0; i < high; i++)
    {
        cout << arrr[i] << " ";
    }
    return 0;
}