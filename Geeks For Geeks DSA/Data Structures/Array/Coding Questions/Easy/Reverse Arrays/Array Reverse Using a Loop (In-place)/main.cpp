// Iterative C++ program to reverse an array
#include <iostream>
using namespace std;

/* Function to reverse arr[] from start to end*/
// rvereseArray(arr, 0, sizeOfArray - 1);
//              arr, start, end
void rvereseArray(int arr[], int start, int end)
{
    // Original option
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // Option B
    // while (start < end)
    // {
    //     std::swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }
}

/* Utility function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

/* Driver function to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);

    // To print original array
    printArray(arr, sizeOfArray);

    // Function calling
    // void rvereseArray(int arr[], int start, int end)
    rvereseArray(arr, 0, sizeOfArray - 1);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, sizeOfArray);

    return 0;
}
