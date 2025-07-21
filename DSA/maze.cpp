#include<iostream>
using namespace std;

int path(int i, int j, int m, int n)
{
    if (i == m || j == n)
    {
        return 0;
    }
    if (i == m-1 && j == n-1)
    {
        return 1;
    }
    int down = path(i + 1, j, m, n);
    int right = path(i, j + 1, m, n);

    return down + right;
}

int main()
{
   int a = path(0, 0, 3, 3);
   cout << a << endl;
   return 0;
}

// (0,0)
// ├── (1,0)
// │   ├── (2,0)
// │   │   └── (2,1)
// │   │       └── (2,2) ✅
// │   └── (1,1)
// │       ├── (2,1)
// │       │   └── (2,2) ✅
// │       └── (1,2)
// │           └── (2,2) ✅
// └── (0,1)
//     ├── (1,1)
//     │   └── (2,2) ✅
//     └── (0,2)
//         └── (1,2)
//             └── (2,2) ✅

// Level 0: path(0, 0)
// ├── Level 1: path(1, 0)
// │   ├── Level 2: path(2, 0)
// │   │   ├── Level 3: path(3, 0) → ❌ out of bounds → 0
// │   │   └── Level 3: path(2, 1)
// │   │       ├── Level 4: path(3, 1) → ❌ → 0
// │   │       └── Level 4: path(2, 2)
// │   │           └── ✅ Base case → 1
// │   └── path(1, 1)
// │       ├── Level 3: path(2, 1)
// │       │   ├── Level 4: path(3, 1) → ❌ → 0
// │       │   └── Level 4: path(2, 2)
// │       │       └── ✅ Base case → 1
// │       └── Level 3: path(1, 2)
// │           ├── Level 4: path(2, 2)
// │           │   └── ✅ Base case → 1
// │           └── Level 4: path(1, 3) → ❌ → 0
// ├── Level 1: path(0, 1)
// │   ├── Level 2: path(1, 1)
// │   │   ├── Level 3: path(2, 1)
// │   │   │   ├── Level 4: path(3, 1) → ❌ → 0
// │   │   │   └── Level 4: path(2, 2)
// │   │   │       └── ✅ Base case → 1
// │   │   └── Level 3: path(1, 2)
// │   │       ├── Level 4: path(2, 2)
// │   │       │   └── ✅ Base case → 1
// │   │       └── Level 4: path(1, 3) → ❌ → 0
// │   └── Level 2: path(0, 2)
// │       ├── Level 3: path(1, 2)
// │       │   ├── Level 4: path(2, 2)
// │       │   │   └── ✅ Base case → 1
// │       │   └── Level 4: path(1, 3) → ❌ → 0
// │       └── Level 3: path(0, 3) → ❌ → 0