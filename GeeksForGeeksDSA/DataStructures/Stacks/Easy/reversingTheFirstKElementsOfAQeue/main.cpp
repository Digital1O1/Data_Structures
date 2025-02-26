#include <iostream>
using namespace std;

class Stack
{
private:
    int arrayCounter;
    int *incomingValue;
    int maxSize;

public:
    Stack(int incomingMaxSize = 0) : maxSize(incomingMaxSize), arrayCounter(-1)
    {
        incomingValue = new int[maxSize];
    }

    ~Stack()
    {
        delete[] incomingValue;
    }

    void push(int x)
    {
        if (arrayCounter + 1 < maxSize)
        {
            incomingValue[++arrayCounter] = x;
        }
    }

    int pop()
    {
        if (arrayCounter >= 0)
        {
            return incomingValue[arrayCounter--];
        }
        return -1; // Return -1 if stack is empty (error case)
    }

    bool isEmpty()
    {
        return arrayCounter == -1;
    }
};

void reverseKElements(int arr[], int elementsInTempStack, int size)
{
    Stack s(elementsInTempStack);

    // Push first elementsInTempStack elements into the stack
    for (int i = 0; i < elementsInTempStack; i++)
    {
        s.push(arr[i]);
    }

    // Pop from stack and overwrite the array (reversing first elementsInTempStack elements)
    for (int i = 0; i < elementsInTempStack; i++)
    {
        arr[i] = s.pop();
    }

    // Output the modified array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int input[] = {1, 2, 5, 6, 7, 8};
    int target = 4; // Reverse first 4 elements
    int arraySize = sizeof(input) / sizeof(input[0]);

    reverseKElements(input, target, arraySize);

    return 0;
}
