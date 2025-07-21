#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];                // Assuming max size is within 1000
    bool present[1001] = {false}; // Index 1 to n, initialized to false

    // Read the array and mark numbers as present
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 1 && arr[i] <= n)
        {
            present[arr[i]] = true;
        }
    }

    bool missingFound = false;

    // Check for missing numbers
    for (int i = 1; i <= n; i++)
    {
        if (present[i] != true)
        {
            cout << i << " ";
            missingFound = true;
        }
    }

    if (missingFound != true)
    {
        cout << -1;
    }

    cout << endl;
    return 0;
}