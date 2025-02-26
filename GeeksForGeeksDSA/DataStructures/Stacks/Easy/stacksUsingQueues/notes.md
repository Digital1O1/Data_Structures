# [Implement Stack using Queues](https://www.geeksforgeeks.org/implement-stack-using-queue/)

## Big idea 
- A stack can be implemented using `two queues` 
- Let the stack to be implemented be `S` and the queues `Q1` and `Q2`
  - The Stack `S` can be implemented in two ways

## Using push()
- This method is computationally costly
- Big idea
  - Keep newly entered element at the front of `Q1` 
  - So that pop operation dequeues from `Q1`. `Q2` is used to put every new element in front of `Q1`.
  - Done so by:
    - Enqueue X to q2
    - Dequeue everything one by one from Q1 and enqueue to Q2
    - Swapping the queues of Q1 and Q2
    - Then Dequeue items from Q1 and return it 
  
```cpp
/* Program to implement a stack using
two queue */
#include <iostream>
using namespace std;

class Stack {
    // Two arrays to simulate the queues
    int arr1[100], arr2[100];
    int top1, top2;

public:
    Stack() {
        top1 = top2 = -1; // Initialize both "queues" as empty
    }

    // Push an element onto the stack
    void push(int x) {
        // Push x first in empty arr2
        arr2[++top2] = x;

        // Push all the remaining elements from arr1 to arr2
        while (top1 != -1) {
            arr2[++top2] = arr1[top1--];
        }

        // Swap the arrays
        int* temp = arr1;
        arr1 = arr2;
        arr2 = temp;

        // Reset top2 for arr2
        top2 = -1;
    }

    // Pop an element from the stack
    void pop() {
        if (top1 == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top1--; // Remove the top element from arr1
    }

    // Get the top element of the stack
    int top() {
        if (top1 == -1) {
            return -1; // Empty stack
        }
        return arr1[top1];
    }

    // Get the current size of the stack
    int size() {
        return top1 + 1;
    }
};

// Driver code
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Current size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    cout << "Current size: " << s.size() << endl;

    return 0;
}
// With arrays 


#include <iostream>
using namespace std;

class Stack {
    // Two arrays to simulate the queues
    int arr1[100], arr2[100];
    int top1, top2;

public:
    Stack() {
        top1 = top2 = -1; // Initialize both "queues" as empty
    }

    // Push an element onto the stack
    void push(int x) {
        // Push x first in empty arr2
        arr2[++top2] = x;

        // Push all the remaining elements from arr1 to arr2
        while (top1 != -1) {
            arr2[++top2] = arr1[top1--];
        }

        // Swap the arrays
        int* temp = arr1;
        arr1 = arr2;
        arr2 = temp;

        // Reset top2 for arr2
        top2 = -1;
    }

    // Pop an element from the stack
    void pop() {
        if (top1 == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top1--; // Remove the top element from arr1
    }

    // Get the top element of the stack
    int top() {
        if (top1 == -1) {
            return -1; // Empty stack
        }
        return arr1[top1];
    }

    // Get the current size of the stack
    int size() {
        return top1 + 1;
    }
};

// Driver code
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Current size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    cout << "Current size: " << s.size() << endl;

    return 0;
}

```

