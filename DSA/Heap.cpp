// Heap in C++ (using priority_queue)

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> max;

    max.push(30);
    max.push(10);
    max.push(50);

    cout << "Max-Heap: ";
    while (!max.empty())
    {
        cout << max.top() << " "; // print largest
        max.pop();
    }
}