// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    // Reference link : https://www.youtube.com/watch?v=O0By4Zq0OFc&ab_channel=BackToBackSWE
    Node* reverse(Node* head)
    {
        // Base case
    	if (head == NULL || head->next == NULL)
    		return head;

    	/* reverse the rest list and put
    	the first element at the end */

        // Takes us 'down' to the next node
    	Node* rest = reverse(head->next);

        // Reverse the link on the last two
        head->next->next = head;

    	/* tricky step -- see the diagram */
    	head->next = NULL;

    	/* fix the head pointer */
    	return rest;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.head = ll.reverse(ll.head);

    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}
