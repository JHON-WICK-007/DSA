#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    s.pop(); // removes 30

    cout << "Top after pop: " << s.top() << endl; // 20

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// Stack (LIFO : Last In, First Out)

// ✔️ Main Operations:
// push(x) → add element
// pop() → remove top element
// top() → get top element
// empty() → check if stack is empty