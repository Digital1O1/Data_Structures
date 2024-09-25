// https://www.geeksforgeeks.org/program-to-reverse-an-array/

/*
Input: original_array[] = {1, 2, 3} Output: array_reversed[] = {3, 2, 1}
Input: original_array[] = {4, 5, 1, 2}
Output: array_reversed[] = {2, 1, 5, 4}
*/

#include <iostream>

using namespace std;

int main()
{
    int original_array[] = {1, 2, 3, 4, 5};
    int sizeOriginalArray = sizeof(original_array) / sizeof(original_array[0]);
    int array_reversed[sizeOriginalArray];
    int reverseCounter = 0;

    // Start at the end of
    for (int forwardCounter = sizeOriginalArray - 1; forwardCounter >= 0; --forwardCounter)
    {
        // Have the original array decrement with forwardCounter
        // While saving the new array by incrementing reverseCounter
        array_reversed[reverseCounter++] = original_array[forwardCounter];
    }

    // Output the reversed array
    for (int i = 0; i < sizeOriginalArray; ++i)
    {
        cout << array_reversed[i] << " ";
    }
    cout << endl;

    return 0;
}