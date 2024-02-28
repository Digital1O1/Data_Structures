# [Array Data Structure](https://www.geeksforgeeks.org/array-data-structure/)

## What is an array : Part 1
- Collection of items stored in contiguous memory locations
- The idea
  - Store multiple items of the same data type together 
  - Makes it easier to calculate the position of each element by just adding an offset to the base value
    - Example : The memory location of the first element of the array 

![!\[alt text\](../../../Array-data-structure.png)
](../../Screenshots/Array-data-structure.png)

## What is an array : [Part 2](https://www.geeksforgeeks.org/what-is-array/)

### Is the array always a fixed size?
- Pretty much, it can't be changed
- Since memory is statically allocated for it
  - Only the compiler can destory it

<br>

# [Introduction to Arrays – Data Structure and Algorithm Tutorials](https://www.geeksforgeeks.org/introduction-to-arrays-data-structure-and-algorithm-tutorials/)

## Basic terminologies of an Array
- Index : How the elements are identified as 
  - Index starts at 0
- Element : Items stored in an array 
  - Can be access by their index 
- Length
  - Determined by the number of elements it contains 

## Representation of an Array

![!\[alt text\](../../../array.png)
](../../Screenshots/array.png)

![!\[alt text\](../../../Arraydeclaration-660x168.png)
](../../Screenshots/Arraydeclaration-660x168.png)
### This declaration is considered static or compile-time memory allocation
- Long story short : the array element's memory is allocated when a program is compiled

## Can you make a dynamic array?
- Short answer : [Yes](https://www.geeksforgeeks.org/how-do-dynamic-arrays-work/)
- Though [dynamic memory allocation](https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/) 

## Example of dynamic memory allocation

```cpp
// First example
int *array = new int[5];

// Second example
#include <iostream>

int main() {
    int size;
    
    // Prompt the user to enter the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    
    // Dynamically allocate memory for the array
    int* arr = new int[size];
    
    // Fill the array with values
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }
    
    // Display the values in the array
    std::cout << "Values in the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Deallocate the dynamically allocated memory
    delete[] arr;
    
    return 0;
}


```

## Three-dimensional array
- Can also be considered an array of two-dimensional arrays
![!\[alt text\](../../../3D-array.png)
](../../Screenshots/3D-array.png)
## Type of array operations
- Traversal --> Moving through the elements in the array
- Insertion --> Adding a new element in an array
- Deletion  --> Deleting an element from the array
- Searching --> Searching for an element in the array
- Sorting   --> Keeping the order of elements in the array 

## Advantages of using Arrays
- Memory-efficeient in storing data
  - Due to data storage in contguous memory locations
- Random accessing elements is allowed 
  - Makes accessing element positions faster
- They have better cache locality 
  - Makes big difference in performance 
- Arrays
  - Represent multiple data items of the same type using single name
  - Store multiple data of similar types with the same name
- Array D.S used to implement other D.S like  
  - Linked lists
  - Stacks 
  - Queues
  - Trees
  - Graphs

## Disadvantages of Arrays
- They have fixed size
  - Can't be increased/decreased 
  - Array of fixed size --> static array
- Allocating less memory than required could result in losing data
- Arrays are homogenous in nature
  - Can't store values of different data types
- Arrays stored in contguous memory locations
  - Makes deletion and insertion difficult to implement
  - To resolve this, Linked lists are used

## Application of arrays
- Used in look up tables
- Different sorting algorithms
  - Bubble sort
  - Insertion sort
  - Merge sort
  - Quick sort

<br>

# [Subarrays, Subsequences, and Subsets in Array](https://www.geeksforgeeks.org/array-subarray-subsequence-and-subset/?ref=lbp)

## What's a subarray 
- Contguous part of an array
  - Aka : An array inside another array

## Generally speaking
- For an array of size ```n```
  - There's --> ``` n * (n+1) / 2 ``` non-empty sub arrays
- Example
  - We have an 
    - Array of ```[1, 2, 3, 4] ```
    - There's 10 non-empty sub-arrays that are as followed
      - ``` (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4), and (1,2,3,4)```
        ![alt text](<../../Screenshots/Screenshot 2024-02-27 184239.png>)


## Subsequence
- A sequence that's derivable from another sequence 
  - Done by removing 
    - Zeros 
    - Elements 
  - Doing so doesn't change the order of the remaining elements
  - Generally speaking
    - If we have a sequence of size ```n```
    - We can have ```(2^n -1)``` non empty sub-sequences in total 
  - Example : There's 15 sub-sequences and they are:
    - ``` (1),(2),(3),(4),(1,2),(1,3),(1,4),(2,3),(2,4),(3,4),(1,2,3),(1,2,4),(1,3,4),(2,3,4),(1,2,3,4). ```
    
      ![alt text](<../../Screenshots/Screenshot 2024-02-27 185631.png>)


## Subset
- If a ``` set ``` has it's element belonging to ``` another set ```
  - It's known to be a ``` subset ``` of the other set
- Denoted as ``` ⊆ ```
  - If ``` A ``` is a subset of ``` B ``` 
    - It's represented as ``` A ⊆ B ```
- Example
  - Set_A = {m, n, o, p, q}, Set_ B = {k, l, m, n, o, p, q, r}
  - So then ``` A ⊆ B ``` 
  
  ![alt text](<../../Screenshots/Screenshot 2024-02-27 185959.png>)

<br>

# [Array | Searching](https://www.geeksforgeeks.org/array-data-structure/array-searching/?ref=lbp)

## Most commonly used searching algorithms
- Linear Search
- Binary Search
- Ternary Search

## Linear Search
- Defined as
  - Sequential search algorithm
  - Starts at one end --> Goes through each element in list until desired element or group of elements is found
    - It will keep going until then
  - Time complexity : O(N)
    - N = lenght of array

## Binary Search
- Used in ``` sorting an array ```
- Elements found by 
  - Repeatedly dividing the search interval in half 
  - Deciding the next interval to find the element
  - Time complexity : ```O(log2N)```
    - N = lenght of array
  - One thing to note
    - Array ``` must be sorted ``` in increasing/decreasing order

## Ternary Search
- Divide and conquer algorithm
- Similar to binary search where we ``` divide the array into two parts ```
  - But we divide it into ``` three parts ``` 
  - Then determine which has the ``` key/searched element ```
- This algorithm ``` must be sorted ```
- Time complexity : ``` O(log3N) ```
  - N = lenght of array

```

         |
      O(n^2)         O(n^2) actual direction 
         |            /
         |           /
         |          /
         |         /
         |        /
         |       /
         |      /
         |     /
         |    /
         |   /
         |  /
         | /           O(n) actual direction -->
    O(n) |------------------ 
         |                     \
         |                      \
         |                       \
         |                        \
         |                         \
         |                          \
         |                           \
         |                            \
         |                             \
         |                              \
         |                               \
         |                                \
         |                               O(log n) actual direction
         |
         |
         |
         |
         |
         |
         |
         |
         |
         |
         |
    O(log n)  -------------------------

```