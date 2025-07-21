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
    Node *NN = new Node;
    NN->data = item;
    NN->next = nullptr;

    if (start == nullptr)
    {
        start = NN;
    }
    else
    {
        Node *temp = start;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = NN;
    }
}

// Delete from the end
void deleteFromEnd(Node *&start)
{
    if (start == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // If there's only one node
    if (start->next == nullptr)
    {
        delete start;
        start = nullptr;
        cout << "Last node deleted." << endl;
        return;
    }

    // Traverse to second-last node
    Node *temp = start;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = nullptr;

    cout << "Last node deleted." << endl;
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
    insertAtEnd(start, 30); // List: 10 -> 20 -> 30

    cout << "Original list: ";
    display(start);

    deleteFromEnd(start); // Deletes 30

    cout << "After deleting from end: ";
    display(start); // 10 -> 20

    return 0;
}