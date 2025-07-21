#include<iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0) return 1;
    if (x == 0) return 0;
    return x * power(x, n-1);
}
int main()
{
    power(2, 3);
    cout << "2^3 = " << power(2, 3) << endl;
    return 0;
}

// | Function Call | Returns           |
// | ------------- | ----------------- |
// | `power(2, 3)` | 2 × power(2, 2)   |
// | `power(2, 2)` | 2 × power(2, 1)   |
// | `power(2, 1)` | 2 × power(2, 0)   |
// | `power(2, 0)` | 1 (base case)     |
// | Final Result  | 2 × 2 × 2 × 1 = 8 |