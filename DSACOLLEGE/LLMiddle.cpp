#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at middle position
void insertMid(Node *&start, int item, int pos)
{
    Node *NN = new Node;
    NN->data = item;
    NN->next = nullptr;

    // Case: Empty list or inserting at position 0 (front)
    if (start == nullptr || pos == 0)
    {
        NN->next = start;
        start = NN;
        return;
    }

    Node *temp = start;
    Node *t2;
    int count = 1;

    // Traverse to (pos - 1)th node safely
    while (count < pos && temp->next != nullptr)
    {
        temp = temp->next;
        count++;
    }

    t2 = temp->next;
    temp->next = NN;
    NN->next = t2;
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

// Main
int main()
{
    Node *start = nullptr;

    // Insert some nodes
    insertMid(start, 30, 0); // List: 30
    insertMid(start, 10, 0); // List: 10 -> 30
    insertMid(start, 20, 1); // List: 10 -> 20 -> 30
    insertMid(start, 25, 2); // List: 10 -> 20 -> 25 -> 30

    display(start);

    return 0;
}