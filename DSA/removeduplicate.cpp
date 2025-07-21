#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(const string &str, int idx, string newstr, bool seen[26]) 
{
    if (idx == str.size()) 
    {
        cout << newstr << endl;
    }

    char current = str[idx];
    if (seen[current - 'a'] == true) 
    {
        return removeDuplicates(str, idx + 1, newstr, seen);
    } 
    else 
    {
        seen[current - 'a'] = true;
        return removeDuplicates(str, idx + 1, newstr + current, seen);
    }
}

int main() 
{
    string input = "abbccda";
    bool seen[26] = {false};

    string result = removeDuplicates(input, 0, "", seen);
    return 0;
}

// | Step | `idx` | `current` | `seen[current - 'a']` | `newstr` Before | Action            | `newstr` After |
// | ---- | ----- | --------- | --------------------- | --------------- | ----------------- | -------------- |
// | 1    | 0     | `'a'`     | false                 | `""`            | Add `'a'`         | `"a"`          |
// | 2    | 1     | `'b'`     | false                 | `"a"`           | Add `'b'`         | `"ab"`         |
// | 3    | 2     | `'b'`     | true                  | `"ab"`          | Skip `'b'`        | `"ab"`         |
// | 4    | 3     | `'c'`     | false                 | `"ab"`          | Add `'c'`         | `"abc"`        |
// | 5    | 4     | `'c'`     | true                  | `"abc"`         | Skip `'c'`        | `"abc"`        |
// | 6    | 5     | `'d'`     | false                 | `"abc"`         | Add `'d'`         | `"abcd"`       |
// | 7    | 6     | `'a'`     | true                  | `"abcd"`        | Skip `'a'`        | `"abcd"`       |
// | 8    | 7     | —         | —                     | `"abcd"`        | Reached base case | Print `"abcd"` |