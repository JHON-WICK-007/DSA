#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; // First line: number of elements

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Second line: array elements
    }

    int x;
    cin >> x; // Last line: value to search

    int comparisons = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == x)
        {
            cout << i << endl;           // Print index
            cout << comparisons << endl; // Print number of comparisons
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Element " << x << " is not present in the array" << endl;
        cout << comparisons << endl;
    }

    return 0;
}