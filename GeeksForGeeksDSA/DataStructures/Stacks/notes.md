# [What is Stack Data Structure? A Complete Tutorial](https://origin.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/)

---

## What is a Stack?
- A **linear data structure** that follows the **LIFO** (Last In First Out) principle.
  - The **last element inserted** is the **first** to be popped out.
  - Both **insertion** and **deletion** operations occur at **one end** only.
- Keep in mind
  - Last element in array is what the operations such as pop()/push() operate out of
  - Last element in array == "Top" of the stack
---

## LIFO (Last In First Out) Principle

### Representation of Stack Data Structure
- Stack follows the **LIFO principle**, where the element pushed **last** is popped **first**.

![Stack Representation](Screenshots/Stack-representation-in-Data-Structures-(1).webp)

### Types of Stacks
#### 1. Fixed Stack
- Has a **fixed size** and cannot grow or shrink dynamically.
- If the stack is **full**:
  - An **overflow error** occurs when adding elements.
- If the stack is **empty**:
  - An **underflow error** occurs when removing elements.

#### 2. Dynamic Size Stack
- Can **grow** or **shrink** dynamically.
- If the stack is **full**:
  - The stack automatically **increases its size** to accommodate new elements.
- If the stack is **empty**:
  - The stack size will **decrease**.
- Implemented using a **linked list**, allowing for easy resizing.

---

## Basic Operations on a Stack
- **`push()`**: Inserts an element into the stack.
- **`pop()`**: Removes an element from the stack.
- **`top()`**: Returns the top element of the stack.
- **`isEmpty()`**: Returns `true` if the stack is empty, otherwise `false`.
- **`isFull()`**: Returns `true` if the stack is full, otherwise `false`.
- Last element in array == Top of stack
### Implementing a Stack
- Maintain a reference to the **top item** of the stack.

---

## Push Operation
Adds an item to the stack. If the stack is full, it throws an **overflow condition**.

### Algorithm for Push Operation
1. Before pushing an element, check if the stack is full:
   - If **full** → **Stack Overflow** (cannot insert the element).
   - If **not full**:
     - Increment the `top` by 1 (`top = top + 1`).
     - Insert the new value at the top position.
2. Continue adding elements until the stack reaches its capacity.

![Push Operation](Screenshots/Push-Operation-in-Stack-(1).webp)

---

## Pop Operation
Removes the top item from the stack, following the **LIFO principle**. Triggers an **underflow condition** if the stack is empty.

### Algorithm
1. Check if the stack is empty (`top == -1`):
   - If **yes**: **Stack Underflows** (cannot remove any element).
2. Otherwise:
   - Store the value at `top`.
   - Decrement `top` by 1 (`top = top - 1`).
   - Return the stored value.

![alt text](Screenshots/Pop-Operation-in-Stack-(1).webp)
---

## Top or Peek Operation
Retrieves the top element of the stack without removing it.

### Algorithm
1. Check if the stack is empty (`top == -1`):
   - If **yes**: Print **“Stack is empty”**.
2. Otherwise:
   - Return the element stored at `index = top`.
![alt text](Screenshots/Top-or-Peek-Operation-in-Stack-(1).webp)
---

## isEmpty Operation
Checks if the stack is empty.

### Algorithm
1. Check the value of `top`:
   - If `top == -1`: Return `true` (stack is empty).
   - Otherwise: Return `false` (stack is not empty).
![alt text](Screenshots/isEmpty-Operation-in-Stack-(1).webp)
---

## isFull Operation
Checks if the stack is full.

### Algorithm
1. Check the value of `top`:
   - If `top == capacity - 1`: Return `true` (stack is full).
   - Otherwise: Return `false` (stack is not full).
![alt text](Screenshots/isFull-Operation-in-Stack-(1).webp)

--- 

# [Implement Stack using Array](https://www.geeksforgeeks.org/implement-stack-using-array/)

## To implement stack using arrays
- Initialize an array 
  - Treat the `end` as `the stack's TOP` 
  - Implement push/pop/peek operations
  - Handle cases when stack is either `empty` or `full`

## Push opeartion in stacks 
- Adds item to the stack 
- If stack is full --> There will be a `overflow` condition 

### Algorithm for `Push` operation 
- Before pushing element to stack
  - Check if stack is `full` 
- If stack is full (top == capacity -1)      
  - Stack `overflows` 
  - Can't insert element into stack
- If stack NOT full 
  - Increment the value of `top` by 1 (top = top +1)
    - insert new value at `top position`
- Check geeksforgeeks for picture reference 

### `Pop` operations in stacks
- Removes item from stack
- Items popped in the `reversed order` in which they're pushed 
- If stack is `empty`
  - It has the `underflow` condition

### Algorithm for `Pop` operation 
- Before popping element from stack 
  - Check if it's empty
  - If empty (top == -1)
    - Has `Stack underflow` condition 
    - Can't remove element from stack 
  - If `NOT` empty
    - Decrement the value of top by 1 (top = top -1)

### Top or Peek Operation in Stack
- Returns the top element of the stack.

### Algorithm for Top Operation
- Before returning the top element from the stack, we check if the stack is empty.
- If the stack is empty (`top == -1`), we simply print "Stack is empty".
- Otherwise, we return the element stored at index `top`.

### isEmpty Operation in Stack
- Returns true if the stack is empty, else false.

### Algorithm for isEmpty Operation
- Check for the value of `top` in stack.
- If `(top == -1)`, then the stack is empty so return true.
- Otherwise, the stack is not empty so return false.

### isFull Operation in Stack
- Returns true if the stack is full, else false.

### Algorithm for isFull Operation
- Check for the value of `top` in stack.
- If `(top == capacity-1)`, then the stack is full so return true.
- Otherwise, the stack is not full so return false.

# C++ implementation 
```cpp
/* C++ program to implement basic stack 
operations */
#include <iostream>
using namespace std; 

#define MAX 1000 

class Stack 
{ 
    int top; 

public: 
    int a[MAX]; // Maximum size of Stack 

      /*
         Class constuctor that initalizes values every time a new class object is made
         
         'Stack' is the dependent name that lets us refer to the current classs being defined. Using 'stack' as the dependent name in the constuctor let's us create an instance of the same type that's currently being defined so we can create a new object that has the same properties/behaviors as the current object but in a different capacity
         
         Example : if we have an existing `Stack` object with capacity 5, we can create a new object with capacity 10 using the constructor `Stack(int capacity) : top(-1), capacity(capacity)`. This allows us to reuse the same code for creating and managing stacks, but with different capacities.

         Stack(int capacity) : top(-1), capacity(capacity) --> constructor initializer list
            - top and capacity are 'member variables' that have values assigned to them 
            - See below for example

         For example, if you wanted to add a new member variable called `loop` to the `Stack` class and initialize it with the value 23, you could modify the constructor
         like this:

         class Stack {
            private:
               int top;
               int capacity;
               int loop = 23; // initializer list
            public:
               Stack(int capacity) : top(-1), capacity(capacity), loop(23) {}
         };




      */
   Stack(int capacity) : top(-1), capacity(capacity) 
   {
      data = new int[capacity];
   }
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
/*
   ------------------- Notes -------------------

   - The '::' is the scope resolution operator 
      - Used to access members of a :
         - Class
         - Namespace 
         - Template from within other classes/namespaces/templates

   - In the case of 'Stack::push(int x)
      - It's a member function of the 'Stack' class
      - The '::' isused to get access of a member function within the 'Stack' class
         - Like the variable 'a'

   - 
*/
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 

int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; // Remember the first element is the 'top' for FILO a[0]
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 

bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    
    //print top element of stack after popping 
    cout << "Top element is : " << s.peek() << endl; 
    
    //print all elements in stack : 
    cout <<"Elements present in stack : "; 
    while(!s.isEmpty()) 
    { 
        // print top element in stack 
        cout << s.peek() <<" "; 
        // remove top element in stack 
        s.pop(); 
    } 

    return 0; 
}
```

# Disadvantage of Array Implementations 
- Not dynamic 
  - Can't grow/shrink based on needs during runtime 
- Total size of stack must be defined beforehand

---

# [Applications, Advantages and Disadvantages of Stack](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-stack/)

## Application of stacks
### Function calls
- To keep track of return addresses of function calls
- Lets program to return to correct location after a function is done executing
### Recusion 
- Stacks used to store local variables and return addresses of recursive function calls
- Lets programs keep track of current state of recursion 
### Expression evaluations 
- Used to evaluate expressions in `postfix` notation (Reverse Polish Notation)
### Syntax parsing
- Stacks used to check validity of syntax in programming languages and in other formal languages 
### Memory management
- Stacks used to allocate/manage memory in some OSs and programming languages 

# Advantages of Stacks
- **Simplicity:** 
  - Easy to use/understand 
  - Suitable for wide range of applications
- **Efficiency:** 
  - Operations like push/pop done on stack performed in constant time (O(1))
  - Providing efficient access to data
- **Last-in, First-out (LIFO):** 
  - Last element added to the stack `is the first removed` 
  - Useful in numerous situations like `function calls` and `expression evaluations`
- **Limited Memory Usage:** 
  - Stacks only store elements that have been pushed onto them
  - Makes them memory efficient compared to other DS

# Disadvantages of Stacks
- **Limited Access:** 
  - Can only access elements from the top
  - Makes it difficult to retrieve/modify elements in the middle of the stack
- **Potential for Overflow:** 
  - If more elements pushed to a stack than it can hold --> overflow error --> loss of data
- **Not Suitable for Random Access:** 
  - Can't randomly access elements in Stacks 
  - Stacks unsuitable for applications where elements need to be access in particular order
- **Limited Capacity:** 
  - Stacks have fixed capacity 
  - Can be a problem if the number of elements are unknown or highly variable 