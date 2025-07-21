#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at front
void insertFront(Node *&start, int item)
{
    Node *NN = new Node; // Create new node
    NN->data = item;     // Assign data
    NN->next = nullptr;  // Initialize next as NULL

    if (start == nullptr)
    {
        start = NN; // If list is empty
        return;
    }
    else
    {
        NN->next = start; // Link new node to current head
        start = NN;       // Update head to new node
        return;
    }
}

// Display the list
void display(Node *&start)
{
    while (start != nullptr)
    {
        cout << start->data << " -> ";
        start = start->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *start = nullptr;

    insertFront(start, 30);
    insertFront(start, 20);
    insertFront(start, 10); // List: 10 -> 20 -> 30

    display(start);

    return 0;
}

// Step 1: insertFront(start, 30)

// start
//  ↓
// [30 | NULL]

// Step 2: insertFront(start, 20)

// start
//  ↓
// [20 | • ] → [30 | NULL]

// Step 3: insertFront(start, 10)

// start
//  ↓
// [10 | • ] → [20 | • ] → [30 | NULL]