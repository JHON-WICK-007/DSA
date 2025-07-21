#include<iostream>
using namespace std;

void sumof(int i,int n, int sum)
{
    if (i == n)
    {
        sum += i;
        cout << sum << endl;
        cout << i << endl;
        return;
    }
    sumof(i + 1, n, sum + i);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    sumof(1, n, 0);
    return 0;
}

// | Function Call     | i | sum                           |
// | ----------------- | - | ----------------------------- |
// | `sumof(1, 5, 0)`  | 1 | 0                             |
// | `sumof(2, 5, 1)`  | 2 | 1                             |
// | `sumof(3, 5, 3)`  | 3 | 3                             |
// | `sumof(4, 5, 6)`  | 4 | 6                             |
// | `sumof(5, 5, 10)` | 5 | 10  → `sum += i` → 15 printed |