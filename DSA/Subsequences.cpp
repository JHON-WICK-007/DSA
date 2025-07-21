#include <iostream>
#include <string>
using namespace std;

void printSubsequences(const string &str, int index, string current)
{
    if (index == str.size())
    {
        cout << current << endl; // print current subsequence (including empty string)
        return;
    }

    // Include current character
    printSubsequences(str, index + 1, current + str[index]);

    // Exclude current character
    printSubsequences(str, index + 1, current);
}

int main()
{
    printSubsequences("abc", 0, "");
    return 0;
}

// | Step | Index | Current Subsequence (`current`) | Action        | Next Call(s)                                    |
// | ---- | ----- | ------------------------------- | ------------- | ----------------------------------------------- |
// | 1    | 0     | `""`                            | Include `'a'` | `printSubsequences("abc", 1, "a")`              |
// | 2    | 1     | `"a"`                           | Include `'b'` | `printSubsequences("abc", 2, "ab")`             |
// | 3    | 2     | `"ab"`                          | Include `'c'` | `printSubsequences("abc", 3, "abc")` (print)    |
// | 4    | 2     | `"ab"`                          | Exclude `'c'` | `printSubsequences("abc", 3, "ab")` (print)     |
// | 5    | 1     | `"a"`                           | Exclude `'b'` | `printSubsequences("abc", 2, "a")`              |
// | 6    | 2     | `"a"`                           | Include `'c'` | `printSubsequences("abc", 3, "ac")` (print)     |
// | 7    | 2     | `"a"`                           | Exclude `'c'` | `printSubsequences("abc", 3, "a")` (print)      |
// | 8    | 0     | `""`                            | Exclude `'a'` | `printSubsequences("abc", 1, "")`               |
// | 9    | 1     | `""`                            | Include `'b'` | `printSubsequences("abc", 2, "b")`              |
// | 10   | 2     | `"b"`                           | Include `'c'` | `printSubsequences("abc", 3, "bc")` (print)     |
// | 11   | 2     | `"b"`                           | Exclude `'c'` | `printSubsequences("abc", 3, "b")` (print)      |
// | 12   | 1     | `""`                            | Exclude `'b'` | `printSubsequences("abc", 2, "")`               |
// | 13   | 2     | `""`                            | Include `'c'` | `printSubsequences("abc", 3, "c")` (print)      |
// | 14   | 2     | `""`                            | Exclude `'c'` | `printSubsequences("abc", 3, "")` (print empty) |