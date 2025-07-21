#include <iostream>
using namespace std;

// Function to partition the array (Lomuto partition scheme)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) // choose the last as high because we chooes already the last as pivot
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]); // Place smaller element at correct position
        }
    }

    swap(arr[i + 1], arr[high]); // Move pivot to its correct position
    return i + 1;                // Return pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piindex = partition(arr, low, high); // Get partition index

        quickSort(arr, low, piindex - 1);  // Sort left part from pivot
        quickSort(arr, piindex + 1, high); // Sort right part from pivot
    }
}

int main()
{
    int arr[] = {9, 4, 7, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1); // Sort the entire array

    cout << "quick Sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}