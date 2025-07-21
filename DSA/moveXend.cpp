#include <iostream>
using namespace std;

void move(string str, int idx, int n, string newstr, int &count) 
{
    if(idx == n)
    {
        for (int i = 0; i < count; i++)
        {
            newstr += 'x';
        }
        cout << newstr << endl;
        return;
    }
    if (str[idx] == 'x')
    {
        count++;
    }
    else
    {
        newstr += str[idx];
    }
    move(str, idx + 1, n, newstr, count); 
}

int main()
{
    string str = "axbcxxd";
    int count = 0;

    move(str, 0, str.size(), "", count);
    return 0;
}

// | Step | `idx` | `str[idx]` | `newstr` so far | `count` (number of 'x') | Action                       |
// | ---- | ----- | ---------- | --------------- | ----------------------- | ---------------------------- |
// | 1    | 0     | `'a'`      | `"a"`           | 0                       | Add `'a'` to `newstr`        |
// | 2    | 1     | `'x'`      | `"a"`           | 1                       | Count `'x'`                  |
// | 3    | 2     | `'b'`      | `"ab"`          | 1                       | Add `'b'`                    |
// | 4    | 3     | `'c'`      | `"abc"`         | 1                       | Add `'c'`                    |
// | 5    | 4     | `'x'`      | `"abc"`         | 2                       | Count `'x'`                  |
// | 6    | 5     | `'x'`      | `"abc"`         | 3                       | Count `'x'`                  |
// | 7    | 6     | `'d'`      | `"abcd"`        | 3                       | Add `'d'`                    |
// | 8    | 7     | *(end)*    | `"abcd"`        | 3                       | Append 3 `'x'` → `"abcdxxx"` |