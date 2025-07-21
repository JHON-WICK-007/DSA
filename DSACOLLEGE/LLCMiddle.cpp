#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at end (for setup)
void insertAtEnd(Node *&start, int item)
{
    Node *NN = new Node;
    NN->data = item;

    if (start == nullptr)
    {
        NN->next = NN;
        start = NN;
    }
    else
    {
        Node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = NN;
        NN->next = start;
    }
}

// Insert at given position (after pos nodes) using while loop
void insertAtMiddle(Node *&start, int item, int pos)
{
    if (start == nullptr)
    {
        cout << "List is empty. Use insertAtEnd instead." << endl;
        return;
    }

    Node *NN = new Node;
    NN->data = item;

    Node *temp = start;
    int count = 0;

    while (count < pos)
    {
        temp = temp->next;
        count++;

        if (temp == start)
        {
            cout << "Position out of range." << endl;
            delete NN;
            return;
        }
    }

    NN->next = temp->next;
    temp->next = NN;
}

// Display circular linked list
void display(Node *start)
{
    if (start == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = start;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != start);

    cout << "(Back to start)" << endl;
}

int main()
{
    Node *start = nullptr;

    // Build initial list
    insertAtEnd(start, 10);
    insertAtEnd(start, 20);
    insertAtEnd(start, 30);

    cout << "Original list: ";
    display(start); // 10 -> 20 -> 30

    // Insert 15 after position 0 (after 10)
    insertAtMiddle(start, 15, 0);

    cout << "After middle insertion: ";
    display(start); // 10 -> 15 -> 20 -> 30

    return 0;
}