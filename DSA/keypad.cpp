#include <iostream>
#include <string>
using namespace std;

void key(string str, int index, string combination, string keypad[])
{
    if (index == str.length())
    {
        cout << combination << endl;
        return;
    }

    char current = str[index];
    string map = keypad[current - '0'];

    for (int i = 0; i < map.size(); i++)
    {
        key(str, index + 1, combination + map[i], keypad);
    }
}

int main()
{
    string keypad[] = {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    key("23", 0, "", keypad);
    return 0;
}

// | Step | `index` | `combination` | `str[index]` | `keypad digit` | Action            | Next Call         |
// | ---- | ------- | ------------- | ------------ | -------------- | ----------------- | ----------------- |
// | 1    | 0       | `""`          | `'2'`        | `"def"`        | Try `'d'`         | index = 1, `"d"`  |
// | 2    | 1       | `"d"`         | `'3'`        | `"ghi"`        | Try `'g'`         | index = 2, `"dg"` |
// | 3    | 2       | `"dg"`        | —            | —              | Base case — print | `"dg"`            |
// | 4    | 1       | `"d"`         | `'3'`        | `"ghi"`        | Try `'h'`         | index = 2, `"dh"` |
// | 5    | 2       | `"dh"`        | —            | —              | Base case — print | `"dh"`            |
// | 6    | 1       | `"d"`         | `'3'`        | `"ghi"`        | Try `'i'`         | index = 2, `"di"` |
// | 7    | 2       | `"di"`        | —            | —              | Base case — print | `"di"`            |
// | 8    | 0       | `""`          | `'2'`        | `"def"`        | Try `'e'`         | index = 1, `"e"`  |
// | 9    | 1       | `"e"`         | `'3'`        | `"ghi"`        | Try `'g'`         | index = 2, `"eg"` |
// | 10   | 2       | `"eg"`        | —            | —              | Base case — print | `"eg"`            |
// | 11   | 1       | `"e"`         | `'3'`        | `"ghi"`        | Try `'h'`         | index = 2, `"eh"` |
// | 12   | 2       | `"eh"`        | —            | —              | Base case — print | `"eh"`            |
// | 13   | 1       | `"e"`         | `'3'`        | `"ghi"`        | Try `'i'`         | index = 2, `"ei"` |
// | 14   | 2       | `"ei"`        | —            | —              | Base case — print | `"ei"`            |
// | 15   | 0       | `""`          | `'2'`        | `"def"`        | Try `'f'`         | index = 1, `"f"`  |
// | 16   | 1       | `"f"`         | `'3'`        | `"ghi"`        | Try `'g'`         | index = 2, `"fg"` |
// | 17   | 2       | `"fg"`        | —            | —              | Base case — print | `"fg"`            |
// | 18   | 1       | `"f"`         | `'3'`        | `"ghi"`        | Try `'h'`         | index = 2, `"fh"` |
// | 19   | 2       | `"fh"`        | —            | —              | Base case — print | `"fh"`            |
// | 20   | 1       | `"f"`         | `'3'`        | `"ghi"`        | Try `'i'`         | index = 2, `"fi"` |
// | 21   | 2       | `"fi"`        | —            | —              | Base case — print | `"fi"`            |