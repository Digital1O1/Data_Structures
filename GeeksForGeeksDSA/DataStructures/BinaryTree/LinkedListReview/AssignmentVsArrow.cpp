#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

int main()
{
    Node *head = new Node(10);    // head points to Node(10)
    Node *newNode = new Node(20); // newNode points to Node(20)

    std::cout << "Before updates:\n";
    std::cout << "head points to: " << head->data << "\n";
    std::cout << "newNode points to: " << newNode->data << "\n";

    // Step 1: Using the arrow operator to update `next`
    newNode->next = head; // newNode's next pointer now stores the address of head

    std::cout << "\nAfter newNode->next = head:\n";
    std::cout << "newNode->next points to: " << newNode->next->data << "\n"; // Should print 10

    // Step 2: Using the assignment operator to move `head`
    head = newNode; // Now head moves to newNode

    std::cout << "\nAfter head = newNode:\n";
    std::cout << "head now points to: " << head->data << "\n";         // Should print 20
    std::cout << "head->next points to: " << head->next->data << "\n"; // Should print 10

    return 0;
}
