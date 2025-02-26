#include <iostream>
#include <string>

class Stack
{
private:
    int maxSize;
    int arrayCounter;
    char *incomingCharacter;

public:
    Stack(int size = 100) : maxSize(size), arrayCounter(0), incomingCharacter(new char[maxSize]) {}

    bool push(std::string x)
    {
        if (arrayCounter >= (maxSize - 1))
        {
            std::cout << "Stack Overflow";
            return false;
        }
        for (int i = 0; i < x.length(); i++)
        {
            incomingCharacter[++arrayCounter] = x[i];
        }
        return true;
    }

    int pop()
    {
        if (arrayCounter < 0)
        {
            std::cout << "Stack Underflow";
            return -1;
        }
        else
        {
            int x = incomingCharacter[arrayCounter--];
            return x;
        }
    }

    int peek()
    {
        if (arrayCounter < 0)
        {
            std::cout << "Stack is Empty";
            return -1;
        }
        else
        {
            return incomingCharacter[arrayCounter];
        }
    }

    bool isEmpty()
    {
        return (arrayCounter < 0);
    }

    ~Stack()
    {
        delete[] incomingCharacter;
    }
};

// Driver program to test above functions
int main()
{
    Stack s(100);
    s.push("Testing");
    std::cout << s.peek() << " Popped from stack\n";

    // print all elements in stack :
    while (!s.isEmpty())
    {
        int x = s.pop();
        if (x != -1)
        {
            std::cout << x << " ";
        }
    }

    return 0;
}