#include <iostream>
#include <algorithm> // for std::sort
#include <chrono>    // for timing

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    const int SIZE = 3100;
    int arr[SIZE];

    // Populate the array with random values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }

    // Sorting using Bubble Sort
    int arrBubble[SIZE];
    std::copy(arr, arr + SIZE, arrBubble); // Copy the original array
    auto startBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(arrBubble, SIZE);
    auto endBubble = std::chrono::high_resolution_clock::now();
    auto durationBubble = std::chrono::duration_cast<std::chrono::nanoseconds>(endBubble - startBubble).count();

    // Sorting using Selection Sort
    int arrSelection[SIZE];
    std::copy(arr, arr + SIZE, arrSelection); // Copy the original array
    auto startSelection = std::chrono::high_resolution_clock::now();
    selectionSort(arrSelection, SIZE);
    auto endSelection = std::chrono::high_resolution_clock::now();
    auto durationSelection = std::chrono::duration_cast<std::chrono::nanoseconds>(endSelection - startSelection).count();

    // Sorting using Insertion Sort
    int arrInsertion[SIZE];
    std::copy(arr, arr + SIZE, arrInsertion); // Copy the original array
    auto startInsertion = std::chrono::high_resolution_clock::now();
    insertionSort(arrInsertion, SIZE);
    auto endInsertion = std::chrono::high_resolution_clock::now();
    auto durationInsertion = std::chrono::duration_cast<std::chrono::nanoseconds>(endInsertion - startInsertion).count();

    // Sorting using C++'s built-in sort function (Quick Sort)
    int arrSTL[SIZE];
    std::copy(arr, arr + SIZE, arrSTL); // Copy the original array
    auto startSTL = std::chrono::high_resolution_clock::now();
    std::sort(arrSTL, arrSTL + SIZE);
    auto endSTL = std::chrono::high_resolution_clock::now();
    auto durationSTL = std::chrono::duration_cast<std::chrono::nanoseconds>(endSTL - startSTL).count();

    std::cout << "Time taken for Bubble Sort: " << durationBubble << " nanoseconds" << std::endl;
    std::cout << "Time taken for Selection Sort: " << durationSelection << " nanoseconds" << std::endl;
    std::cout << "Time taken for Insertion Sort: " << durationInsertion << " nanoseconds" << std::endl;
    std::cout << "Time taken for C++'s sort function: " << durationSTL << " nanoseconds" << std::endl;

    return 0;
}
