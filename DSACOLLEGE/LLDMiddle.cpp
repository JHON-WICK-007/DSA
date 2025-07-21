#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at a specific position (1-based index)
void insertAtPosition(Node *&start, int item, int pos)
{
    Node *NN = new Node;
    NN->data = item;
    NN->next = nullptr;

    if (pos == 1)
    {
        NN->next = start;
        start = NN;
        return;
    }

    Node *temp = start;
    int count = 1;

    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position!" << endl;
        delete NN;
        return;
    }

    NN->next = temp->next;
    temp->next = NN;
}

// ✅ Delete node at a specific position (1-based index)
void deleteAtPosition(Node *&start, int pos)
{
    if (start == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Case 1: delete head
    if (pos == 1)
    {
        Node *temp = start;
        start = start->next;
        delete temp;
        return;
    }

    Node *temp = start;
    int count = 1;

    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // If position is invalid or next is null
    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
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

    // Initial list: 10 -> 20 -> 30
    insertAtPosition(start, 10, 1);
    insertAtPosition(start, 20, 2);
    insertAtPosition(start, 30, 3);

    cout << "Before inserting in middle:\n";
    display(start);

    // Insert 99 at position 2 (10 -> 99 -> 20 -> 30)
    insertAtPosition(start, 99, 2);

    cout << "\nAfter inserting 99 at position 2:\n";
    display(start);

    // ✅ Delete node at position 2 (removes 99)
    deleteAtPosition(start, 2);

    cout << "\nAfter deleting node at position 2:\n";
    display(start); // 10 -> 20 -> 30

    return 0;
}