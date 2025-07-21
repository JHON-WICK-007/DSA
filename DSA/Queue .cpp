#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10

    q.pop(); // removes 10

    cout << "Front after pop: " << q.front() << endl; // 20

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

// Queue (FIFO: First In, First Out)

// ✔️ Main Operations:
// push(x) → add at rear
// pop() → remove front
// front() → get front element
// empty() → check if queue is empty