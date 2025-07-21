#include<iostream>
using namespace std;

void firstlast(string str, int idx, char element)
{
    static int first = -1;
    static int last = -1;

    if(idx == str.length())
    {
        cout << "First occurrence: " << first << endl;
        cout << "Last occurrence: " << last << endl;
        return;
    }

    char current = str[idx];
    if(current == element)
    {
        if(first == -1) first = idx; // First occurrence
        last = idx; // Last occurrence
    }

    firstlast(str, idx + 1, element);
}

int main()
{
    string str = "abaacdaefaah";
    firstlast(str, 0, 'a');
    return 0;
}

// | `idx` | `str[idx]` | `first` | `last` | Action                                     |
// | ----- | ---------- | ------- | ------ | ------------------------------------------ |
// | 0     | `'a'`      | **0**   | 0      | First `'a'` → sets both `first` and `last` |
// | 1     | `'b'`      | 0       | 0      | Not `'a'`                                  |
// | 2     | `'a'`      | 0       | **2**  | Found `'a'` → update `last`                |
// | 3     | `'a'`      | 0       | **3**  | Found `'a'` → update `last`                |
// | 4     | `'c'`      | 0       | 3      | Not `'a'`                                  |
// | 5     | `'d'`      | 0       | 3      | Not `'a'`                                  |
// | 6     | `'a'`      | 0       | **6**  | Found `'a'` → update `last`                |
// | 7     | `'e'`      | 0       | 6      | Not `'a'`                                  |
// | 8     | `'f'`      | 0       | 6      | Not `'a'`                                  |
// | 9     | `'a'`      | 0       | **9**  | Found `'a'` → update `last`                |
// | 10    | `'a'`      | 0       | **10** | Found `'a'` → update `last`                |
// | 11    | `'h'`      | 0       | 10     | Not `'a'`                                  |
// | 12    | *(end)*    | 0       | 10     | Reached end → print result                 |