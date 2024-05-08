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
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}
void leftRotate(int arr[], int rotationDistance, int arraySize)
{
    /* To handle if rotationDistance >= arraySize */
    rotationDistance = rotationDistance % arraySize;
    int g_c_d = gcd(rotationDistance, arraySize);
    // Run for number of sets
    for (int i = 0; i < g_c_d; i++)
    {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
        // Does the actual rotation
        //
        while (1)
        {
            int k = j + rotationDistance;
            if (k >= arraySize)
                k = k - arraySize;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 2, arraySize);
    printArray(arr, arraySize);

    return 0;
}