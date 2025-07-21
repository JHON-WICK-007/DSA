#include <iostream>
using namespace std;

int main()
{
    cout << "insertion sort" << endl;
    int arr3[] = {7, 8, 3, 1, 2};

    int n = sizeof(arr3) / sizeof(arr3[0]);
    for (int i = 1; i < n; i++)
    {
        int key = arr3[i];
        int j = i - 1;
        while (j >= 0 && arr3[j] > key)
        {
            arr3[j + 1] = arr3[j];
            j--;
        }
        arr3[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}