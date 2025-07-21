#include <iostream>
using namespace std;

bool sorted(int arr[], int index, int n)
{
    if(index == n-1)
    {
        return true;
    }
    if(arr[index] < arr[index + 1])
    {
        return sorted(arr, index + 1, n);
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool a = sorted(arr, 0, n);

    if (a == true)
    {
        cout << "Array is sorted in ascending order";
    }
    else
    {
        cout << "Array is not sorted in ascending order";
    }
    return 0;
}

// Trace Table for Case 1: 1 2 3 4 5
// | Function Call       | `arr[index]` | `arr[index+1]` | Comparison (`<`) | Return Value         |
// | ------------------- | ------------ | -------------- | ---------------- | -------------------- |
// | `sorted(arr, 0, 5)` | 1            | 2              | ✅ true           | recursive call       |
// | `sorted(arr, 1, 5)` | 2            | 3              | ✅ true           | recursive call       |
// | `sorted(arr, 2, 5)` | 3            | 4              | ✅ true           | recursive call       |
// | `sorted(arr, 3, 5)` | 4            | 5              | ✅ true           | recursive call       |
// | `sorted(arr, 4, 5)` | 5            | -              | reached end      | **true** (base case) |
// | ← return            |              |                |                  | all return **true**  |

// Trace Table for Case 2: 1 2 2 3 4
// | Function Call       | `arr[index]` | `arr[index+1]` | Comparison (`<`) | Return Value      |
// | ------------------- | ------------ | -------------- | ---------------- | ----------------- |
// | `sorted(arr, 0, 5)` | 1            | 2              | ✅ true           | recursive call    |
// | `sorted(arr, 1, 5)` | 2            | 2              | ❌ false          | returns **false** |

// #include <iostream>
// using namespace std;

// bool sorted(int arr[], int index, int n)
// {
//     if(index == 0)
//     {
//         return true;
//     }
//     if(arr[index] > arr[index - 1])
//     {
//         return sorted(arr, index - 1, n);
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     bool a = sorted(arr, n-1, n);

//     if (a == true)
//     {
//         cout << "Array is sorted in ascending order";
//     }
//     else
//     {
//         cout << "Array is not sorted in ascending order";
//     }
// }