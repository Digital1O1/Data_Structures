// Reference link : https://www.geeksforgeeks.org/print-array-after-it-is-right-rotated-k-times/?ref=lbp
#include <iostream>

using namespace std;

void RightRotate(int originalArray[], int arraySize, int rightRotations, int newArray[])
{

    // If rotation is greater
    // than size of array
    // int Array[] = {1, 2, 3, 4, 5};
    // int rightRotations = 2;
    // First time : rightRotation = 2 | arraySize = 4 --> rightRotation = 2 % 4 --> rightRotation = 2
    rightRotations = rightRotations % arraySize;
    for (int i = 0; i < arraySize; i++)
    {
        // First time : i = 0 | rightRotation = 2 --> 0 < 2 --> true
        if (i < rightRotations)
        {

            // Printing rightmost
            // kth elements

            // So then cout << originalArray [ 4 + 0 - 2] --> originalArray[2] --> 3

            // cout << originalArray[arraySize + i - rightRotations] << " ";
            newArray[i] = originalArray[arraySize + i - rightRotations];
        }
        else
        {

            // Prints array after
            // 'rightRotations' elements

            // When `i` = 2 you'll end up here
            // if(2 < 2) --> false --> originalArray[2-2] --> originalArray[0] --> 1
            // cout << (originalArray[i - rightRotations]) << " ";
            newArray[i] = originalArray[i - rightRotations];
        }
    }
}

// Driver code
int main()
{
    int Array[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(Array) / sizeof(Array[0]);
    int rightRotations = 2;
    int *newArray = new int[arraySize]; // Dynamically allocate memory for newArray

    RightRotate(Array, arraySize, rightRotations, newArray);
    cout << "Before " << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cout << Array[i] << " ";
    }

    cout << endl
         << "Rotated Array by 2 :" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << newArray[i] << " ";
    }

    delete[] newArray; // Free dynamically allocated memory
    return 0;
}