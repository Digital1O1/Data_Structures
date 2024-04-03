#include <iostream>

using namespace std;

int main()
{

    // Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    // Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};

    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};

    int arraySize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n------------------------------\n";
    // for (int i = 0; i < arraySize - 1; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         // arr[arraySize - 1] = arr[i];
    //     }
    //     std::cout << arr[i] << " ";
    // }

    // Shift elements to left by 1
    int temp = arr[0];
    for (int i = 0; i < (arraySize - 1); i++)
    {
        // Shift left by 1
        arr[i] = arr[i + 1];
    }
    // Store the last array
    arr[arraySize - 1] = temp;

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}