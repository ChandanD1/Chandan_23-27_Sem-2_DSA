// 13. Implement Binary Search algorithm to search an
// element in an array

// Theory:
// This code implements the binary search algorithm, which efficiently 
// searches for a target element in a sorted array. It divides the 
// array into halves repeatedly until the target element is found or 
// the search interval becomes empty. By comparing the target with 
// the middle element of the array, it determines whether to continue 
// the search in the left or right subarray, effectively reducing the 
// search space with each iteration.

#include <iostream>
using namespace std;

int bst(int arr[], int left, int right, int target) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() 
{
    int n;
    cout << "enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "enter elements of array in sorted order: ";

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int target;
    cout << "enter the element to search: ";
    cin >> target;

    int index = bst(arr, 0, n - 1, target);
    
    if (index != -1)
        cout << "element found at index " << index << endl;
    else
        cout << "element not found" << endl;

    return 0;
}