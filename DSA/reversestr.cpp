#include<iostream>
using namespace std;

void reverse(string str, int n)
{
    cout << str[n];
    if (n == 0) return;
    reverse(str, n-1);
}

int main()
{
    string str = "ABC";
    int n = str.size();

    reverse(str, n-1);
    return 0;
}

// str[0,1,2] = str[A,B,C]
// reverse(str, 2) → prints str[2] = 'C'
// reverse(str, 1) → prints str[1] = 'B'
// reverse(str, 0) → prints str[0] = 'A'