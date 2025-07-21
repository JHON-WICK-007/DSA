#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, s;

    cin >> s >> r;

    int arr[s]; 

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < r; i++)
    {
        int first = arr[0];
        for (int j = 0; j < s - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[s - 1] = first;
    }

    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}