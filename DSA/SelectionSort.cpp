#include <iostream>
using namespace std;

int main()
{
    cout << "selection sort" << endl;
    int arr2[] = {7, 8, 3, 1, 2};

    int n = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr2[j] < arr2[smallest])
            {
                smallest = j;
            }
        }
        swap(arr2[i], arr2[smallest]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }

    cout << endl;
    return 0;
}