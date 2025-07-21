#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; 
}

int main()
{
    int n, key;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search : ";
    cin >> key;

    int index = linearSearch(arr, n, key);

    if (index != -1) cout << "Element " << key << " found at index " << index << "." << endl;
    else             cout << "Element " << key << " not found in the array." << endl;

    return 0;
}

// int arr[] = {10, 20, 30, 40, 50};  // User input
// key = 30;                          // The number to search

// linearSearch(arr, 5, 30)

// | Index | arr\[i] | arr\[i] == key?  |
// | ----- | ------- | ---------------- |
// | 0     | 10      | No               |
// | 1     | 20      | No               |
// | 2     | 30      | ✅ Yes → return 2 |