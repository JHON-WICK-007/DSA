#include <iostream>
#include <string>
using namespace std;

void combination(string str, string perm, int index)
{
    if (str.length() == 0)
    {
        cout << perm << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char current = str[i];
        string newstr = str.substr(0, i) + str.substr(i + 1);
        combination(newstr, perm + current, index + 1);
    }
}

int main()
{
    combination("ABC", "", 0);
    return 0;
}

// | Call Level | `str` | `perm` | `i` | `current` | `newstr` | Action                    |
// | ---------- | ----- | ------ | --- | --------- | -------- | ------------------------- |
// | 0          | ABC   | ""     | 0   | A         | BC       | Call combination(BC, A)   |
// | 1          | BC    | A      | 0   | B         | C        | Call combination(C, AB)   |
// | 2          | C     | AB     | 0   | C         | ""       | Call combination("", ABC) |
// | 3          | ""    | ABC    | -   | -         | -        | **Print: ABC**            |
// | 2          | C     | AB     | X   | X         | X        | Return to level 1         |
// | 1          | BC    | A      | 1   | C         | B        | Call combination(B, AC)   |
// | 2          | B     | AC     | 0   | B         | ""       | Call combination("", ACB) |
// | 3          | ""    | ACB    | -   | -         | -        | **Print: ACB**            |
// | …          | …     | …      | …   | …         | …        | …                         |
// | 3          | ""    | BAC    | -   | -         | -        | **Print: BAC**            |
// | 3          | ""    | BCA    | -   | -         | -        | **Print: BCA**            |
// | 3          | ""    | CAB    | -   | -         | -        | **Print: CAB**            |
// | 3          | ""    | CBA    | -   | -         | -        | **Print: CBA**            |