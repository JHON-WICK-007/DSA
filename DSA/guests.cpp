#include <iostream>
using namespace std;

int guest(int n)
{
    if (n <= 1 )
    {
        return 1;
    }
    int single = guest(n - 1);
    int pair = (n - 1) * guest(n - 2);

    return single + pair;
}

int main()
{
    cout << guest(4) << endl;
    return 0;
}

// guest(4)
// ├── guest(3)                         ← (guest 4 stays single)
// │   ├── guest(2)                     ← (guest 3 stays single)
// │   │   ├── guest(1) = 1             ← (guest 2 stays single)
// │   │   └── 1 * guest(0) = 1         ← (guest 2 pairs with guest 1)
// │   │       → guest(2) = 1 + 1 = 2
// │   └── 2 * guest(1) = 2             ← (guest 3 pairs with guest 2)
// │       → guest(3) = 2 + 2 = 4
// └── 3 * guest(2)                     ← (guest 4 pairs with any of 3 others)
//     ├── guest(1) = 1                 ← (guest 2 stays single)
//     └── 1 * guest(0) = 1             ← (guest 2 pairs with guest 1)
//         → guest(2) = 1 + 1 = 2
//     → 3 * guest(2) = 3 * 2 = 6
// guest(4) = 4 (from guest(3)) + 6 = 10 ✅