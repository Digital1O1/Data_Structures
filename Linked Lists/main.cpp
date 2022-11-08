#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void reverse(struct Node **head)
{
    // Initialize current, previous and next pointers
    Node *current = *head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    // Extra * for head is needed or the following error will pop up
    // 'a value of type 'Node *' cannot be assigned toan entity of tyep "Node **"
    // head = prev; // WRONG
    *head = prev; // Correct
}

// Reference link : https://www.youtube.com/watch?v=LYGbeWnYXd8&ab_channel=NesoAcademy
void add_node_end(struct Node **head_node, int new_data)
{
    // Allocate new node
    Node *new_node = new Node();
    new_node->next = nullptr;
    new_node->data = new_data;

    // This node will be used to traverse throughout the list
    Node *traversing_node = *head_node;
    while (traversing_node->next != NULL)
    {
        traversing_node = traversing_node->next;
    }

    // Establishes the traversing node with the NULL node
    traversing_node->next = new_node;
}
void add_node_beginning(Node **head, int new_data)
{
    // Allocate new node
    Node *new_node = new Node();

    // Have new node point towards current head node
    new_node->next = (*head);

    // Set incoming data into new node
    new_node->data = new_data;

    // Have current head pointer point to new_node
    (*head) = new_node;
}
// Reference link : https://www.youtube.com/watch?v=f1r_jxCyOl0&ab_channel=NesoAcademy
void deleteNode(struct Node **head_node, int position)
{
    Node *current = (*head_node);
    Node *previous = (*head_node);

    // printf("\nDeleting [%d] node", position);

    if (*head_node == NULL)
    {
        printf("List is empty\r\n");
    }
    else if (position == 1)
    {
        *head_node = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->next;
            position--;
        }

        // Updates the traversing node with the previous node link
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}
// Reference link : https://www.youtube.com/watch?v=-4K4n7l9gMg&t=1s&ab_channel=nexTRIE
void insertNode(struct Node **head_node, int position, int new_data)
{
    Node *new_node = *head_node; // Create new node
    new_node->data = new_data;   // Store incoming data into new node

    Node *traversing_node = *head_node; // Have traversing_node linked to head node
    Node *previous_node;                // Create another new node

    // Traverse the list
    for (int i = 0; i < position; i++)
    {
        previous_node = traversing_node;
        traversing_node = traversing_node->next;
    }

    // Think of new_node and traversing_node as the "arrows"
    previous_node->next = new_node;   // Have previous node 'connect' to current node
    new_node->next = traversing_node; // Have the traversing_node variable 'connect' to where were wanting
}
void printNodes(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    int random_num = 0;
    srand(time(NULL));

    // Start with empty list
    Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        random_num = rand() % 10 + 1;
        add_node_beginning(&head, random_num);
    }
    printf("Before\r\n");
    printNodes(head);

    printf("\nAfter deleting node\n");
    random_num = rand() % 10 + 1;

    deleteNode(&head, random_num);
    printNodes(head);

    printf("\nAfter inserting node \r\n");
    random_num = rand() % 10 + 1;

    insertNode(&head, 2, random_num);
    printNodes(head);

    printf("\nAfter inserting node at end \r\n");
    random_num = rand() % 10 + 1;

    add_node_end(&head, random_num);
    printNodes(head);

    printf("\nAfter inserting node at end \r\n");
    reverse(&head);
    printNodes(head);

    return 0;
}