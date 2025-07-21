#include <iostream>
#include <string>
using namespace std;

void generateSubsets(const string &str, int index, string current)
{
    if (index == str.size())
    {
        cout << current << endl; // print current subsequence (including empty string)
        return;
    }

    // Include current character
    generateSubsets(str, index + 1, current + str[index]);

    // Exclude current character
    generateSubsets(str, index + 1, current);
}

int main()
{
    generateSubsets("321", 0, "");
    return 0;
}

// ""
// ├── "3"
// │   ├── "32"
// │   │   ├── "321"   ✅
// │   │   └── "32"    ✅
// │   └── "3"
// │       ├── "31"    ✅
// │       └── "3"     ✅
// └── ""
//     ├── "2"
//     │   ├── "21"    ✅
//     │   └── "2"     ✅
//     └── ""
//         ├── "1"     ✅
//         └── ""      ✅