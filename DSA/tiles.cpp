#include<iostream>
using namespace std;

int tiles(int n, int m)
{
    if(n == m) 
    {
        return 2;
    }
    if(n < m)
    {
        return 1;
    }
    int vertical = tiles(n - m, m);
    int horizontal = tiles(n - 1, m);

    return vertical + horizontal;
}

int main()
{
   cout << tiles(4, 2) << endl;
   return 0;
}

// Level 0: tiles(4, 2)
// ├── vertical = tiles(2, 2)
// │   ├── tiles(2, 2) == m → return 2
// ├── horizontal = tiles(3, 2)
// │   ├── vertical = tiles(1, 2)
// │   │   ├── n < m → return 1
// │   └── horizontal = tiles(2, 2)
// │       ├── tiles(2, 2) == m → return 2