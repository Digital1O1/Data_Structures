# Refresher about `Stacks` versus `Queues`
| Data Structure | Removal Direction | Access Method |
| --- | --- | --- |
| Stack | Last In, First Out (LIFO) | pop() removes from the end (top of the stack) |
| Queue | First In, First Out (FIFO) | pop() removes from the front (first inserted element) |

# Using Level Order Traversal 
- A `NULL` is pushed after `each level` to track the end 
- As nodes are processed 
  - Each node's `nextRight` pointer is set to `the next node` in the queue
- If a `NULL` is encountered and if the queue isn't empty
  - Another NULL is added to mark the end of the next level
  - This ensures all the nodes at the same level are linked
- Check out the following link for the implementation : [here](https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/)

# std::queue<Node*>
## What is it
- First In First Out (FIFO) container adaptor from the C++ STL
- Designed to let you add elements to the back and to remove from the front


## Basic Functions of `std::queue`:
- Here’s a quick comparison of the most-used functions:

Function | What it does | Similar in vector
-----------|---------------|-------------------
`q.push(val)` | Adds `val` to the back of the queue | ✅ `vec.push_back(val)`
`q.pop()` | Removes the front element | ❌ (vector has no direct `pop_front()`)
`q.front()` | Accesses the front element | ❌ (not the same as `vec[0]`)
`q.back()` | Accesses the last (back) element | ✅ `vec.back()`
`q.empty()` | Checks if queue is empty | ✅ `vec.empty()`
`q.size()` | Returns the number of elements | ✅ `vec.size()`


---


# Mistakes that were made

## Mine
```cpp

    void testing(Node *node)
    {
        // Initalize Node* pointers to push incoming values

        queue<Node *> q;
        q.push(node);

        // You only enter this block if the current node is NULL and you pushed node into the queue before you could check

        // Also if the node is valid and not a null the loop doesn't run at all
        if (node == nullptr)
        {
            // Print out values for sanity check
            while (!q.empty())
            {
                std::cout << q.front() << " ";
                q.pop();
            }

            q.push(nullptr); // <-- level end marker
            std::cout << "End of level" << std::endl;
            return;
        }
    }
```

## With corrections

```cpp
    void testing(Node *node)
    {
        if (node == nullptr)
            return;

        queue<Node *> q;
        q.push(node);

        // nullptr when this function first starts off acts as a level 'delimiter' that states where one level of the tree ends/begins
        q.push(nullptr); 

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr != nullptr)
            {
                std::cout << curr->data << " ";

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            else
            {
                std::cout << "| End of level" << std::endl;

                if (!q.empty())
                    q.push(nullptr);
            }
        }
    }
```