#include <stdio.h>

// Binary Search for Ascending Sorted Array
int binarySearchAscending(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid; // Key found
        }
        else if (arr[mid] < key)
        {
            high = mid - 1; // Search in left half
        }
        else
        {
            low = mid + 1; // Search right half
        }
    }

    return -1; // Key not found
}

int main()
{
    // Ascending sorted array
    int arr[] = {99, 89, 79, 69, 59, 49, 39, 29, 19, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 29;

    // Perform Binary Search
    int result = binarySearchAscending(arr, n, key);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", key, result);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}