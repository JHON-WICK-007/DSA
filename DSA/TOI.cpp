#include<iostream>
using namespace std;

void TOI(int n, string source, string helper, string destination)
{
    if (n == 1) 
    {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        return;
    }
    TOI(n - 1, source, destination, helper);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    TOI(n - 1, helper, source, destination);
}

int main()
{
   int n = 2; // Number of disks
   TOI(n, "S", "H", "D");
   return 0;
}

// Initial:
// S: [2, 1]    H: []    D: []

// Step 1: Move disk 1 from S to H
// S: [2]       H: [1]   D: []

// Step 2: Move disk 2 from S to D
// S: []        H: [1]   D: [2]

// Step 3: Move disk 1 from H to D
// S: []        H: []    D: [2, 1]

// | Step | Function Call             | Action (Move)             | Explanation                                          |
// | ---- | ------------------------- | ------------------------- | ---------------------------------------------------- |
// | 1    | `TOI(2, S, H, D)`         | -                         | Begin solving for 2 disks.                           |
// | 2    | → `TOI(1, S, D, H)`       | -                         | Move top disk (disk 1) to Helper.                    |
// | 3    |                           | `Move disk 1 from S to H` | Smallest disk moved from Source to Helper.           |
// | 4    | Back to `TOI(2, S, H, D)` | `Move disk 2 from S to D` | Move larger disk from Source to Destination.         |
// | 5    | → `TOI(1, H, S, D)`       | -                         | Move disk 1 from Helper to Destination.              |
// | 6    |                           | `Move disk 1 from H to D` | Disk 1 reaches Destination, placed on top of disk 2. |

// Call Stack Table — Step by Step
// Step	Call Stack (Top is Last Pushed)	Action
// 1	TOI(2, S, H, D)	Initial call
// 2	TOI(1, S, D, H)	Recursive call to move disk 1
// 3	(Base Case Reached)	Move disk 1 from S to H (print)
// 4	(Return from TOI(1, S, D, H))	Pop base case
// 5	*(Still inside TOI(2, S, H, D))	Move disk 2 from S to D (print)
// 6	TOI(1, H, S, D)	Second recursive call
// 7	(Base Case Reached)	Move disk 1 from H to D (print)
// 8	(Return from TOI(1, H, S, D))	Pop base case
// 9	(Return from TOI(2, S, H, D))	All done