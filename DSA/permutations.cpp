#include<iostream>
#include<string>
using namespace std;

void permutations(string str, string permutation) 
{
    if (str.size() == 0)
    {
        cout << permutation << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++)
    {
        char current = str[i];
        string newstr = str.substr(0, i) + str.substr(i + 1); // remove the current character from the string
        permutations(newstr, permutation + current);
    }
}
int main()
{
    permutations("abc", "");
    return 0;
}

// | Step | `str` | `permutation` | Action                                  |
// | ---- | ----- | ------------- | --------------------------------------- |
// | 1    | abc   | ""            | Loop `i=0` → pick `'a'`, call with `bc` |
// | 2    | bc    | "a"           | Loop `i=0` → pick `'b'`, call with `c`  |
// | 3    | c     | "ab"          | Loop `i=0` → pick `'c'`, call with `""` |
// | 4    | ""    | "abc"         | Base case → print `abc`                 |
// | 5    | c     | "ab"          | Backtrack → done with `i=0`             |
// | 6    | bc    | "a"           | Loop `i=1` → pick `'c'`, call with `b`  |
// | 7    | b     | "ac"          | Loop `i=0` → pick `'b'`, call with `""` |
// | 8    | ""    | "acb"         | Base case → print `acb`                 |
// | 9    | b     | "ac"          | Backtrack → done                        |
// | 10   | abc   | ""            | Loop `i=1` → pick `'b'`, call with `ac` |
// | 11   | ac    | "b"           | Loop `i=0` → pick `'a'`, call with `c`  |
// | 12   | c     | "ba"          | Loop `i=0` → pick `'c'`, call with `""` |
// | 13   | ""    | "bac"         | Base case → print `bac`                 |
// | 14   | ac    | "b"           | Loop `i=1` → pick `'c'`, call with `a`  |
// | 15   | a     | "bc"          | Loop `i=0` → pick `'a'`, call with `""` |
// | 16   | ""    | "bca"         | Base case → print `bca`                 |
// | 17   | abc   | ""            | Loop `i=2` → pick `'c'`, call with `ab` |
// | 18   | ab    | "c"           | Loop `i=0` → pick `'a'`, call with `b`  |
// | 19   | b     | "ca"          | Loop `i=0` → pick `'b'`, call with `""` |
// | 20   | ""    | "cab"         | Base case → print `cab`                 |
// | 21   | ab    | "c"           | Loop `i=1` → pick `'b'`, call with `a`  |
// | 22   | a     | "cb"          | Loop `i=0` → pick `'a'`, call with `""` |
// | 23   | ""    | "cba"         | Base case → print `cba`                 |