#include <iostream>
using namespace std;

int findMissing(int arr[], int n)
{
    int total = n * (n + 1) / 2; 
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }

    return total - sum; 
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int arr[n - 1];

    cout << "Enter " << n - 1 << " elements from 1 to " << n << " (with one number missing):\n";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int missing = findMissing(arr, n);

    cout << "The missing number is: " << missing << endl;

    return 0;
}