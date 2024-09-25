#include <iostream>

using namespace std;

void RightRotate(int originalArray[], int arraySize, int rightRotations)
{

    // If rotation is greater
    // than size of array

    // First time : rightRotation = 2 | arraySize = 4 --> rightRotation = 2 % 4 --> rightRotation = 2
    rightRotations = rightRotations % arraySize;
    int newArray[] = {0}; // This only creates an array size of 1 you need to use DMA 
    for (int i = 0; i < arraySize; i++)
    {
        // First time : i = 0 | rightRotation = 2 --> 0 < 2 --> true
        // So then cout << originalArray [ 4 + 0 - 2] --> originalArray[2] --> 3
        if (i < rightRotations)
        {

            // Printing rightmost
            // kth elements
            cout << originalArray[arraySize + i - rightRotations] << " ";
            newArray[i] = originalArray[arraySize + i - rightRotations];
        }
        else
        {

            // Prints array after
            // 'rightRotations' elements

            // When `i` = 2 you'll end up here
            // if(2 < 2) --> false --> originalArray[2-2] --> originalArray[0] --> 1
            cout << (originalArray[i - rightRotations]) << " ";
            newArray[i] = originalArray[i - rightRotations];
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << newArray[i] << std::endl;
    }
}

// Driver code
int main()
{
    int Array[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(Array) / sizeof(Array[0]);
    int rightRotations = 2;

    RightRotate(Array, arraySize, rightRotations);
}