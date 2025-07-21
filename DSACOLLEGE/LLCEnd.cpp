#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to insert at the end of circular linked list
void insertAtEnd(Node *&start, int item)
{
    Node *NN = new Node; // Step 1: Create new node
    NN->data = item;     // Step 2: Assign data

    if (start == nullptr)
    {
        // Step 3: If list is empty, point to itself
        NN->next = NN;
        start = NN;
    }
    else
    {
        Node *temp = start;
        // Step 4: Traverse to the last node
        while (temp->next != start)
        {
            temp = temp->next;
        }
        // Step 5: Insert new node after last
        temp->next = NN;
        NN->next = start;
    }
}

// Function to display circular linked list
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

    // Insert values at the end
    insertAtEnd(start, 10);
    insertAtEnd(start, 20);
    insertAtEnd(start, 30);
    insertAtEnd(start, 40); // List: 10 -> 20 -> 30 -> 40 -> (Back to 10)

    display(start);

    return 0;
}