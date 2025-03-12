#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {} // Constructor
};

class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete first node
    void deleteFirstNode()
    {
        if (!head)
            return; // Check if the list is empty

        Node *temp = head; // Store the current head node in temp

        // Variable = Action On Varible
        head = head->next; // Move head to the next node
        delete temp;       // Delete the old head node
    }

    // Delete a node by value
    void deleteNode(int key)
    {
        if (!head)
            return;

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        while (curr && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (!curr)
            return; // Key not found
        prev->next = curr->next;
        delete curr;
    }

    // Print the list
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;

    // Insert elements
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Initial List: ";
    list.printList();

    // Delete first node
    list.deleteFirstNode();
    cout << "After deleting first node: ";
    list.printList();

    // Delete a specific node
    list.deleteNode(4);
    cout << "After deleting node 4: ";
    list.printList();

    return 0;
}
