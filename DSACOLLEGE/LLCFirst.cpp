#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Insert at front in circular linked list
void insertFront(Node *&start, int item)
{
    Node *NN = new Node;
    NN->data = item;

    if (start == nullptr)
    {
        // First node creation
        NN->next = NN; // Points to itself
        start = NN;
    }
    else
    {
        Node *temp = start;
        // Traverse to the last node
        while (temp->next != start)
        {
            temp = temp->next;
        }
        NN->next = start;
        temp->next = NN;
        start = NN;
    }
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

    insertFront(start, 30);
    insertFront(start, 20);
    insertFront(start, 10); // List: 10 -> 20 -> 30 -> (Back to 10)

    display(start);

    return 0;
}