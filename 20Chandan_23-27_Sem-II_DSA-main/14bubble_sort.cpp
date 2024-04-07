// 14. Implement Bubble sort algorithm to sort elements of 
// an array in ascending and descending order.

// Theory:
// This code demonstrates two sorting functions: ascendingsort and 
// descendingsort. Both functions implement the bubble sort algorithm 
// to sort an array of integers in ascending and descending order, 
// respectively. Bubble sort repeatedly steps through the list, 
// compares adjacent elements, and swaps them if they are in the wrong 
// order. This process is repeated until the array is sorted.

#include <iostream>
using namespace std;

void ascendingsort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void descendingsort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    cout << "enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "enter elements of array: ";

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    ascendingsort(arr, n);
    cout << "array in ascending order: ";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    descendingsort(arr, n);
    cout << "array in descending order: ";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

