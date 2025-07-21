#include <iostream>
#include <iterator>
using namespace std;

// Merges two sorted halves of the array into one sorted portion
void add(int arr[], int si, int mid, int ei)
{
    int *addarr = new int[ei - si + 1]; // Dynamically allocate temp array to store merged result

    int index1 = si;      // Starting index of left subarray
    int index2 = mid + 1; // Starting index of right subarray
    int x = 0;            // Index for addarr

    // Merge the two subarrays into addarr in sorted order
    while (index1 <= mid && index2 <= ei)
    {
        if (arr[index1] <= arr[index2]) // Compare elements from both subarrays
        {
            addarr[x] = arr[index1]; // Take from left if smaller or equal
            x++;
            index1++;
        }
        else
        {
            addarr[x] = arr[index2]; // Take from right otherwise
            x++;
            index2++;
        }
    }

    // Copy any remaining elements from left subarray
    while (index1 <= mid)
    {
        addarr[x] = arr[index1];
        x++;
        index1++;
    }

    // Copy any remaining elements from right subarray
    while (index2 <= ei)
    {
        addarr[x] = arr[index2];
        x++;
        index2++;
    }

    // Copy the merged and sorted result back to the original array
    for (int i = 0, j = si; i < x; i++, j++)
    {
        arr[j] = addarr[i]; // arr[si to ei] = sorted merged values
    }

    delete[] addarr; // Free dynamically allocated memory
}

// Recursively divides the array into halves and calls merge (add)
void divide(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return; // Base case: array of 1 element is already sorted
    }

    int mid = si + (ei - si) / 2; // Find the middle index

    divide(arr, si, mid);     // Recursively sort left half
    divide(arr, mid + 1, ei); // Recursively sort right half
    add(arr, si, mid, ei);    // Merge both sorted halves
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8};       // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    divide(arr, 0, n - 1); // Call merge sort

    cout << "merged sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print sorted array
    }
}

//                [6 3 9 5 2 8]
//               /            \
//          [6 3 9]         [5 2 8]
//         /      \         /     \
//     [6 3]     [9]     [5 2]     [8]
//    /    \               /  \
// [6]    [3]           [5]  [2]

//  ---Merge Phase---

//    [3 6]               [2 5]
//          \           /
//          [3 6 9]   [2 5 8]
//                \   /
//           [2 3 5 6 8 9]

// | Step | Left Index (si) | Right Index (ei) | Subarray                | Operation             | Result After Merge      |
// | ---- | --------------- | ---------------- | ----------------------- | --------------------- | ----------------------- |
// | 1    | 0               | 5                | \[6, 3, 9, 5, 2, 8]     | Divide into 0-2 & 3-5 | —                       |
// | 2    | 0               | 2                | \[6, 3, 9]              | Divide into 0-1 & 2   | —                       |
// | 3    | 0               | 1                | \[6, 3]                 | Divide into 0 & 1     | —                       |
// | 4    | 0               | 0                | \[6]                    | Base case             | \[6]                    |
// | 5    | 1               | 1                | \[3]                    | Base case             | \[3]                    |
// | 6    | 0               | 1                | \[6, 3]                 | Merge \[6] + \[3]     | **\[3, 6]**             |
// | 7    | 2               | 2                | \[9]                    | Base case             | \[9]                    |
// | 8    | 0               | 2                | \[3, 6] + \[9]          | Merge                 | **\[3, 6, 9]**          |
// | 9    | 3               | 5                | \[5, 2, 8]              | Divide into 3-4 & 5   | —                       |
// | 10   | 3               | 4                | \[5, 2]                 | Divide into 3 & 4     | —                       |
// | 11   | 3               | 3                | \[5]                    | Base case             | \[5]                    |
// | 12   | 4               | 4                | \[2]                    | Base case             | \[2]                    |
// | 13   | 3               | 4                | \[5, 2]                 | Merge \[5] + \[2]     | **\[2, 5]**             |
// | 14   | 5               | 5                | \[8]                    | Base case             | \[8]                    |
// | 15   | 3               | 5                | \[2, 5] + \[8]          | Merge                 | **\[2, 5, 8]**          |
// | 16   | 0               | 5                | \[3, 6, 9] + \[2, 5, 8] | Final Merge           | **\[2, 3, 5, 6, 8, 9]** |