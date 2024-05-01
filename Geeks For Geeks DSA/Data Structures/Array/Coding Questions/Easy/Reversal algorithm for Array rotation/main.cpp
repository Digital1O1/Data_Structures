#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    /*
        Reference link : https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/?ref=lbp

        Problem
            - Given array arr[] of size N
            - Task : rotate array by D positions TO THE LEFT
    */

    int arr[] = {1, 6, 7, 8};
    int d = 3;

    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i] << " ";
    }
    std::cout << "\n\n================================\n\n";

    reverse(arr, arr + sizeArr);
    // 1 6 7 8 --> 8 7 6 1

    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i] << " ";
    }

    std::cout << "\n\n================================\n\n";

    reverse(arr, arr + d);
    // 8 7 6 1 -->
    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i] << " ";
    }

    std::cout << "\n\n================================\n\n";

    reverse(arr + d, arr + sizeArr);
    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i] << " ";
    }
    // Expected output : Output: 3, 4, 5, 6, 7, 1, 2
    return 0;
}