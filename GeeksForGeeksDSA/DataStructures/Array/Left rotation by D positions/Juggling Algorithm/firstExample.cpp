#include <iostream>
#include <stdio.h>
// Reference link : https://www.geeksforgeeks.org/array-rotation/?ref=lbp
// Approach 2 : Juggling Algorithm
/*
    Reference link : https://www.geeksforgeeks.org/array-rotation/?ref=lbp
                     https://www.youtube.com/watch?v=utE_1ppU5DY&t=1s

    Approach 2 : Juggling Algorithm
        - Array is divided into different sets
        - Number of sets equal to GCD of arraySize and rotationDistance so that elements are 'X' distance apart
            - And rotate elements within sets by 1 position to the left

    High overview
        - Calculate GCD between length and distance to be moved
        - The elements are only shifted within the set
        - Start with temp = arr[0]
            - Keep moving arr[i+rotationDistance] to arr[i]
            - Finally store temp at the right place

    Actual steps taken place
        - Perform rotationDistance % arraySize
            - To keep the value of rotationDistance within range of the array
            - 'rotationDistance' is the number of times the array is rotated
            - 'arraySize' is the size of the array
        - Calculate GCD(arraySize,rotationDistance) to divide array into sets
        - Run loop from 0 to the value calculated by GCD
            - Store value of arr[i] in temporary variable
            - Run while looop to update values according to the set
        - After exiting the while loop
            - Assign the value of arr[j] to the value of the temporary variable
*/
int gcd(int rotationDistance, int arraySize)
{
    if (arraySize == 0)
        return rotationDistance;

    else
        return gcd(arraySize, rotationDistance % arraySize);
}
void leftRotate(int array[], int rotationDistance, int arraySize)
{
    /* To handle if rotationDistance >= arraySize */
    rotationDistance = rotationDistance % arraySize;
    int gcd_rotation_array = gcd(rotationDistance, arraySize);
    // Iterate through the number of sets
    // gcd_rotation_array = 1
    for (int setIndex = 0; setIndex < gcd_rotation_array; setIndex++)
    {
        /* move setIndex-th values of blocks */
        // First iteration || Second iteration
        // setIndex = 0 || setIndex = 1
        // temporary will hold 1 || temporary will hold 2
        int temporary = array[setIndex];
        // currentIndex = 0 || currentIndex = 1
        int currentIndex = setIndex;
        // Does the actual rotation to whatever rotationDistance is set to
        while (1)
        {
            // int arr[] = {1, 2, 3, 4, 5, 6, 7};
            //            first iteration      || second iteration
            // Remember : currentIndex = 0     || currentIndex = 1
            //            rotationDistance = 2 || rotationDistance = 2

            // nextIndex = 0 + 2 --> 2 || nextIndex = 1 + 2 --> 3
            // So nextIndex = 2        || nextIndex = 3
            int nextIndex = currentIndex + rotationDistance;

            // Remember : nextIndex = 2 || nextIndex = 3
            //            arraySize = 7 || arraySize = 7
            // if(2 >= 7) --> true      || if(3 >= 7) --> true
            if (nextIndex >= arraySize)
                // nextIndex = 2 - 7    || nextIndex = 3 - 7
                nextIndex = nextIndex - arraySize;
            // nextIndex = 5 || nextIndex = 4
            // setIndex  = 0 || setIndex = 1
            // This breaks the while loop to let for loop iterate to the next set
            if (nextIndex == setIndex)
                break;
            // currentIndex = 0 || currentIndex = 1
            // nextIndex    = 2 || nextIndex = 4
            // array[0] = array[2] --> 0 = 3 --> array[0] == 3 || array[1] = array[4] --> 2 = 5 --> array[2] = 5
            array[currentIndex] = array[nextIndex];

            // currentIndex = 0 || currentIndex = 1
            // nextIndex = 2 || nextIndex = 4
            currentIndex = nextIndex;
        }
        // currentIndex = 0 || currentIndex = 1
        // temporary = 1 || currentIndex = 2
        array[currentIndex] = temporary;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 2, arraySize);
    printArray(arr, arraySize);

    return 0;
}