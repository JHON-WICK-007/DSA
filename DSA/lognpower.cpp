#include<iostream>
using namespace std;

int logn(int x, int n)
{
    if (n == 0) return 1;
    if (x == 0) return 0;
    if (n % 2 == 0) return logn(x, n / 2) * logn(x, n / 2);
    else return logn(x, n / 2) * logn(x, n / 2) * x;
}

int main()
{   
    logn(2, 3);
    cout << "2^3 = " << logn(2, 3) << endl;
    return 0;
}

// | Step | Call       | n Value                 | Computation                        |
// | ---- | ---------- | ----------------------- | ---------------------------------- |
// | 1    | logn(2, 3) | Odd                     | logn(2,1) → 1 → return `1*1*2 = 2` |
// | 2    | logn(2, 1) | Odd                     | logn(2,0) → 1 → return `1*1*2 = 2` |
// | 3    | logn(2, 0) | 0                       | Base case → returns 1              |
// | 4    | Returns    | logn(2,3) = `2*2*2 = 8` |                                    |