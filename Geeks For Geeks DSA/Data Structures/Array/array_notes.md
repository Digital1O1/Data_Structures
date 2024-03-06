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

---
<br>

# [Search, Insert, and Delete in an Unsorted Array | Array Operations](https://www.geeksforgeeks.org/search-insert-and-delete-in-an-unsorted-array/?ref=lbp)

## Search Operation
- In an ```unsorted array``` 
  - Search operations can be performed by ```linear traversal``` from the first --> last
- Time complexity : O(N)

```cpp
// C++ program to implement linear
// search in unsorted array
#include <bits/stdc++.h>
using namespace std;

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	
	// If the key is not found
	return -1;
}

// Driver's Code
int main()
{
	int arr[] = { 12, 34, 10, 6, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Using a last element as search element
	int key = 40;

	// Function call
	int position = findElement(arr, n, key);

	if (position == -1)
		cout << "Element not found";
	else
		cout << "Element Found at Position: "
			<< position + 1;

	return 0;
}

// This code is contributed
// by Akanksha Rai

```

## Insert Operations (At the end)
- In an ```unsorted array``` 
  - Insertion faster when compared to ```sorted array```
  - Due to not having to worry about the  position which the element is to be placed
- Time complexity : O(1)

    ![alt text](<../../Screenshots/Screenshot 2024-03-05 201335.png>)

```cpp
#include <iostream>
using namespace std;

// Inserts a key in arr[] of given capacity.
// n is the current size of arr[]. This
// function returns n + 1 if insertion
// is successful, else n.
int insertSorted(int arr[], int n, int key, int capacity)
{
	// Cannot insert more elements if n is
	// already more than or equal to capacity
	if (n >= capacity)
		return n;

	arr[n] = key;
	return (n + 1);
}

int main()
{
	int arr[20] = { 12, 16, 20, 40, 50, 70 };
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int n = 6;
	int i, key = 26;

	cout << "Before Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Inserting key
	n = insertSorted(arr, n, key, capacity);

	cout << "\nAfter Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;

  //Before Insertion: 12 16 20 40 50 70 
  //After Insertion: 12 16 20 40 50 70 26 
}

```

## Insert at any position
- Is done by shifting elements ```to the right``` of the required position
![alt text](<../../Screenshots/Screenshot 2024-03-05 204047.png>)


```cpp
// C++ Program to Insert an element
// at a specific position in an Array

#include <bits/stdc++.h>
using namespace std;

// Function to insert element
// at a specific position
void insertElement(int arr[], int n, int x, int pos)
{
	// shift elements to the right
	// which are on the right side of pos
	for (int i = n - 1; i >= pos; i--)
		arr[i + 1] = arr[i];

	arr[pos] = x;
}

// Driver's code
int main()
{
	int arr[15] = { 2, 4, 1, 8, 5 };
	int n = 5;

	cout<<"Before insertion : ";
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	int x = 10, pos = 2;

	// Function call
	insertElement(arr, n, x, pos);
	n++;

	cout<<"After insertion : ";
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

	return 0;
}

```

## Delete operations
- The element to be deleted is searched by using ```linear search```
- Deletion operation performed followed by shifting the elements
- Time complexity : 0(1)

![alt text](<../../Screenshots/Screenshot 2024-03-05 204321.png>)

```cpp
// C++ program to implement delete operation in a
// unsorted array
#include <iostream>
using namespace std;

// To search a key to be deleted
int findElement(int arr[], int n, int key);

// Function to delete an element
int deleteElement(int arr[], int n, int key)
{
	// Find position of element to be deleted
	int pos = findElement(arr, n, key);

	if (pos == -1) {
		cout << "Element not found";
		return n;
	}

	// Deleting element
	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];

	return n - 1;
}

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;

	return -1;
}

// Driver's code
int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	cout << "Array before deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	

	// Function call
	n = deleteElement(arr, n, key);

	cout << "\n\nArray after deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

// This code is contributed by shubhamsingh10


```