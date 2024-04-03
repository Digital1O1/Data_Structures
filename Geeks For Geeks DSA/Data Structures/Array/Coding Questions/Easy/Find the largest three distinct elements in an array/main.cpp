// Refernece link : https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/?ref=lbp
#include <iostream>
#include <algorithm> // for std::sort
#include <chrono>    // for timing
using namespace std;

int main()
{
    int arr[] = {10, 4, 3, 50, 23, 90};
    int sizeArray = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + sizeArray);

    for (int i = 0; i < sizeArray; i++)
    {
        std::cout << "At position " << i << " value : " << arr[i] << std::endl;
    }

    for (int i = (sizeArray / 2); i < sizeArray; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}