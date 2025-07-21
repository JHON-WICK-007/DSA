#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at the end
void insertAtEnd(Node *&start, int item)
{
    Node *NN = new Node; // Step 1: create new node
    NN->data = item;     // Step 2: set data
    NN->next = nullptr;  // Step 3: next is NULL

    if (start == nullptr)
    {
        // Step 4: If list is empty, new node is the first node
        start = NN;
        return;
    }
    else
    {
        // Step 5: Traverse to the end of the list
        Node *temp = start;
        while (temp->next == nullptr)
        {
            temp = temp->next;
        }
        // Step 6: Link last node to new node
        temp->next = NN;
        return;
    }
}

// Display the list
void display(Node *start)
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

    insertAtEnd(start, 10);
    insertAtEnd(start, 20);
    insertAtEnd(start, 30); // List: 10 -> 20 -> 30 -> NULL

    display(start);

    return 0;
}

// Step 1: insertAtEnd(start, 10)

// start
//  ↓
// [10 | NULL]

// Step 2: insertAtEnd(start, 20)

// start
//  ↓
// [10 | • ] → [20 | NULL]

// Step 3: insertAtEnd(start, 30)

// start
//  ↓
// [10 | • ] → [20 | • ] → [30 | NULL]