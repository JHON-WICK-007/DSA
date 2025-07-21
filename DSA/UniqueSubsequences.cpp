#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void printSubsequences(const string &str, int index, string newstr, unordered_set<string> &set)
{
    if (index == str.size())
    {
        if (set.find(newstr) != set.end())
            return; // Already printed this subsequence
        
        set.insert(newstr);
        cout << newstr << endl;
        return;
    }

    // Include current character
    printSubsequences(str, index + 1, newstr + str[index], set);

    // Exclude current character
    printSubsequences(str, index + 1, newstr, set);
}

int main()
{
    unordered_set<string> hashSet; 
    printSubsequences("aaa", 0, "", hashSet);
    return 0;
}

// | Step | Index | Current Subsequence (`newstr`) | Action        | Subsequence Printed? | `unordered_set` Contents (after step) |
// | ---- | ----- | ------------------------------ | ------------- | -------------------- | ------------------------------------- |
// | 1    | 0     | `""`                           | Include `'a'` | No (not base case)   | {}                                    |
// | 2    | 1     | `"a"`                          | Include `'a'` | No (not base case)   | {}                                    |
// | 3    | 2     | `"aa"`                         | Include `'a'` | No (not base case)   | {}                                    |
// | 4    | 3     | `"aaa"`                        | Base case     | Yes                  | {"aaa"}                               |
// | 5    | 2     | `"aa"`                         | Exclude `'a'` | Yes                  | {"aaa", "aa"}                         |
// | 6    | 1     | `"a"`                          | Exclude `'a'` | Yes                  | {"aaa", "aa", "a"}                    |
// | 7    | 2     | `"a"`                          | Include `'a'` | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 8    | 3     | `"aa"`                         | Base case     | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 9    | 2     | `"a"`                          | Exclude `'a'` | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 10   | 1     | `""`                           | Exclude `'a'` | No (not base case)   | {"aaa", "aa", "a"}                    |
// | 11   | 2     | `"a"`                          | Include `'a'` | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 12   | 3     | `"aa"`                         | Base case     | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 13   | 2     | `""`                           | Exclude `'a'` | No (not base case)   | {"aaa", "aa", "a"}                    |
// | 14   | 3     | `"a"`                          | Base case     | Duplicate → No print | {"aaa", "aa", "a"}                    |
// | 15   | 3     | `""`                           | Base case     | Yes                  | {"aaa", "aa", "a", ""}                |