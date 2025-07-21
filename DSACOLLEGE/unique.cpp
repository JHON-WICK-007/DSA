#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1000];        // Assuming maximum 1000 elements
    int freq[1000] = {0}; // Frequency array initialized to 0

    // Input elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Count frequency of each element
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        freq[i] = count;
    }

    // Find and print the unique (non-repeating) element
    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 1)
        {
            cout << arr[i] << endl;
            break;
        }
    }

    return 0;
}
