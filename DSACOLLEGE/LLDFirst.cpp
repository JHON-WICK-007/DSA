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
    Node *NN = new Node;
    NN->data = item;
    NN->next = nullptr;

    if (start == nullptr)
    {
        start = NN;
    }
    else
    {
        NN->next = start;
        start = NN;
    }
}

// Delete from front
void deleteFront(Node *&start)
{
    if (start == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = start;  // Step 1: Store the current first node (head) in a temporary pointer. so we can not lose it the next step.
    start = start->next; // Step 2: Move the head pointer to the second node (next of current head). we put the start to the second node so the first node will be deleted.
    delete temp;         // Step 3: Delete the original head node to free memory

    cout << "First node deleted." << endl;
}

// Display the list (pass by value to avoid modifying original start)
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

    insertFront(start, 30);
    insertFront(start, 20);
    insertFront(start, 10); // List: 10 -> 20 -> 30

    cout << "Original list: ";
    display(start);

    deleteFront(start); // Now list: 20 -> 30

    cout << "After deleting from front: ";
    display(start);

    return 0;
}