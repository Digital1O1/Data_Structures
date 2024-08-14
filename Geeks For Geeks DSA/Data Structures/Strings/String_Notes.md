# [String Data Structures](https://www.geeksforgeeks.org/string-data-structure/?ref=shm#what-is-a-string)

## What exactly is a string
- A sequence of characters used to represent text
  - Represented as an array of bytes/words that store a sequence of chracters
- Commonly used to store/manipulate textual data 
  - Can be manipulated using various operations like
    - `Concatenation` 
    - `Substring extraction`
    - `Comparison` 
- Difference between `character array` and a `string`
  - `Strings` are terminated by special character `\0`

## String data type
- Treated as a `distinct data type`
  - Meaning they have their own set of `operations`/`properties` 
  - They can be declared/manipulated using specific string-related functions/methods 

## String operations
### The following operations let developers manipulate/process string data efficiently
- Concatenation: 
  - Combining two strings to create a new string.
- Length: 
  - Determining the number of characters in a string.
- Access: 
  - Accessing individual characters in a string by index.
- Substring: 
  - Extracting a portion of a string.
- Comparison: 
  - Comparing two strings to check for equality or order.
- Search: 
  - Finding the position of a specific substring within a string.
- Modification: 
  - Changing or replacing characters within a string.
- Compare
  - s1.compare(s2)
    - Determines which one is smaller
- Reverse
  - `reverse()`
- Sort
  - `sort()`

## Application of String
- Text processing
  - Use extensively for text processing tasks such as
    - Searching
    - Manipulating
    - Analyzing text data
- Data representation
  - Strings are fundamental for representing/manipulating data in formats like `JSON`, `XML` and `CSV`
- Encryption/Hashing
  - Strings commonly used in `encryption`/`hashing` algorithms to 
    - Secure sensitive data
    - Ensure data integrity 
- Database Opeartions 
  - Strings are esential when working with DB, to include `storing`/`querying` text-based data

## Advantages 
- Widely supported
  - Considered a fundamental data type in most programming languages 
- Efficient manipulation
  - Lots of algorithms and data structures have been writtent oefficiently manipulate strings
  - Such as
    - String matching algorithms
    - String compression algorithms
    - Data structures such as   
      - Tries
      - Suffix arrays
- Ability to model real world data
  - Like names/addresses and other forms of text data
- Text mining/NLPs
  - Strings used as input to algorithms for text mining/NLPs such as
    - Sentiment analysis 
    - Named entity recognition 

## Disadvantages
- Encoding issues
  - Strings can be represented in different encodings such as `UTF-8` or `UTF-16`
  - Can cause compatibility issues when processing strings from different sources
- Immutable
  - Strings often implemented as immutable D.S 
  - Meaning that once a string is created `it can't be modified`
  - This can lead to additional overhead when it comes to manipulating strings 
    - Since new strings have to be created `for every modification`
- Security vulnerabilities
  - Strings are prone to `buffer overflows` or `injection attacks` if not handled properly
  - Since strings can be manipulated by the attacker to execute arbitary code or access sensitive data

# Basics of Strings

## [How are strings represented in memory](https://www.geeksforgeeks.org/introduction-to-strings-data-structure-and-algorithm-tutorials/)
- Strings can be referred to as either as :
  - Using a character pointer
  - Character array
    - When declared as such, they're stored like other types of arrays in C
    - Example : if `str[]` is a `auto variable` then the string is stored in the `stack segment`
    - If it's a `global/static variable` then the data is stored in the data segment

        ![alt text](Screenshots/Strings-660x496.png)

## General operations performed on String

### Concatenation of Strings
- Aka : combining more than one string together 
- Using [built in methods](https://www.geeksforgeeks.org/string-concatenation-in-cpp/)

#### 6 methods
- `append()`
- The `+` operator
- `strcat()` function
- Using a for loop [NOT DISCUSSED FURTHER IN MARKDOWN NOTES]
- Using inheritance [NOT DISCUSSED FURTHER IN MARKDOWN NOTES]
- Using `Friend Function` and `strcat()` function [NOT DISCUSSED FURTHER IN MARKDOWN NOTES]

### The `append()` function
- Member function of the std::string class
- Can concatenate two C++ style strings as shown in the example below

```cpp
// C++ Program for string
// concatenation using append
#include <iostream>
using namespace std;

// Driver code
int main()
{
	string init("this is init");
	string add(" added now");

	// Appending the string.
	init.append(add);

	cout << init << endl; // Output : this is init added now

	return 0;
}

```

### The `+` operator
- Easiest method to concatenate two strings 
- Only works with `C++ style` strings 
``` cpp
// C++ Program for string
// concatenation using '+' operator
#include <iostream>
using namespace std;

// Driver code
int main()
{
	string init("this is init");
	string add(" added now");

	// Appending the string.
	init = init + add;

	cout << init << endl;
	return 0;
}
```

### Using `strcat()`
- Built in function in `<string.h>`
- Only works for `C-style strings`
- Does NOT work for C++ style strings
  - Aka std::string objects
- Syntax : `char * strcat(char * init, const char * add);`

```cpp
// C++ Program for string
// concatenation using strcat
#include <iostream>
#include <string.h>
using namespace std;

// Driver code
int main()
{
	char init[] = "this is init";
	char add[] = " added now";

	// Concatenating the string.
	strcat(init, add);

	cout << init << endl;
  // this is init added now

	return 0;
}

```
### Not listing out other methods cause it doesn't seem worth the time

---

# [Iterate over characters of a string in C++](https://www.geeksforgeeks.org/iterate-over-characters-of-a-string-in-c/?ref=roadmap)

## Given string `str` of lenght `N` traverse and print all the characters of the given string

## Example 

```
Input: str = “GeeksforGeeks”
Output: G e e k s f o r G e e k s

Input: str = “Coder”
Output: C o d e r
```

### Basic AF approach 
- Use loop to iterate over the range `[0, N-1]`
```cpp
// C++ program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to traverse the string and 
// print the characters of the string 
void TraverseString(string &str, int N) 
{ 
	// Traverse the string 
	for (int i = 0; i < N; i++) { 

		// Print current character 
		cout<< str[i]<< " "; 
	} 
	
} 

// Driver Code 
int main() 
{ 
	string str = "GeeksforGeeks"; 
	
	// Stores length of the string 
	int N = str.length(); 

	TraverseString(str, N); 
  // G e e k s f o r G e e k s
} 

```

### Using the `auto` keyword

```cpp
// C++ program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to traverse the string and 
// print the elements of the string 
void TraverseString(string &str, int N) 
{ 
	// Traverse the string 
	for (auto &ch : str) { 

		// Print current character 
		cout<< ch<< " "; 
	} 
} 
// Driver Code 
int main() 
{ 
	string str = "GeeksforGeeks"; 

	// Stores length of the string 
	int N = str.length(); 

	TraverseString(str, N); 
} 

```

```cpp
// Side note about & in for loop
std::string str = "hello";

// Without &, creates a copy of each character
for (auto ch : str) {
    ch = toupper(ch); // Modifies the copy, not the original string
}
std::cout << str << std::endl; // Output: hello (no change)

// With &, operates on the original string
for (auto &ch : str) {
    ch = toupper(ch); // Modifies the original string
}
std::cout << str << std::endl; // Output: HELLO (modified string)
```

### Using a `iterator`

```cpp
// C++ program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to traverse the string and 
// print the elements of the string 
void TraverseString(string &str, int N) 
{ 
	
	// Stores address of 
	// a character of str 
	string:: iterator it; 
	
	// Traverse the string 
	for (it = str.begin(); it != str.end(); 
								it++) { 
		// Print current character 
		cout<< *it<< " "; 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "GeeksforGeeks"; 
	
	
	// Stores length of the string 
	int N = str.length(); 
	TraverseString(str, N); 
  // G e e k s f o r G e e k s

} 

```

#### All three methods have the same time complexity and auxiliary space
##### Time complexity : 0(N)
##### Auxiliary space : 0(1)

---

# [Getting a substring in C](https://www.geeksforgeeks.org/get-a-substring-in-c/?ref=roadmap)

## Task : Given `str`, `pos`, and `len` that defines the starting and length of subarray. The objective is to generate a substring of size `len` starting from the index `pos`

```
# Example
Input: Str =”the”, pos=1, len=2
Output:  “th”
Explanation: substrings will be: “”, “t”, “h”, “e”, “th”, “he”, “the”.

Input: Str =”geeks”, pos=3, length=3
Output: “eks” 
Explanation: substrings are: “”, ” g”, “e”, “e”, “k”, “s”, “ge”, “ee”, “ek”, “ks”, “gee”, “eek”, “eks”, “geek”, “eeks”, “geeks”.
```

## How to solve the problem
- Create character array 
- Put characters starting from `pos` to the character array to generate the substring

## Example

```
Consider a string str=”abcde” , pos = 2, len = 3.

=> At i = 2 our ans = “c”. 

=> At i = 3, the character is ‘d’.
So add ‘d’ to the answer. 
Our ans = “cd”

=> At i = 4, the character is ‘e’.
So add ‘e’ to the answer.
Your ans = “cde”.
```

```cpp
// C implementation of code
#include <stdio.h>
#include <string.h>

// Function to get substr in C
void getString(int pos, int len, int i, char string[])
{

    char substring[1000];

    while (i < len) {
        substring[i] = string[pos + i - 1];
        i++;
    }

    substring[i] = '\0';

    // Print the result
    printf(substring);
    printf("\n");
    return 0;
}

// Driver code
int main()
{

    int pos, len, i = 0;

    // Testcase1
    char string[14] = "geeksforgeeks";

    // Initialize pos, len i.e., starting
    // index and len upto which we have to
    // get substring respectively.
    pos = 6;
    len = 5;
    printf("String: %s ", string);
    printf("\nsubstring is: ");

    // Function call
    getString(pos, len, i, string);

    // Testcase2
    char string2[5] = "abcde";
    pos = 1;
    len = 3;
    i = 0;
    printf("\nString: %s ", string2);
    printf("\nsubstring is: ");

    // Function call
    getString(pos, len, i, string2);

    return 0;

    // String: geeksforgeeks 
    // substring is: forge

    // String: abcde 
    // substring is: abc
}

```

## Can also use `strncpy()` function in C
- To copy substring from given input string
- Takes 3 parameters : `strncpy(destination_string , input_string+pos ,len);`
  - Destination string
  - Source string
  - Starting index
  - Lenght of substring we need to copy

### Example
```cpp
// C implementation of code
#include <stdio.h>
#include <string.h>

// Driver code
int main()
{
    int pos, len;

    // Testcase1
    char string[14] = "geeksforgeeks";
    char substring[20];

    // Initialize pos, len i.e., starting
    // index and len upto which we have to
    // get substring respectively.
    pos = 6;
    len = 5;
    printf("String: %s ", string);
    printf("\nsubstring is: ");

    // Using strncpy function to 
    // copy the substring
    // strncpy(destination_string, source_string + starting index, lenght of substring we want to copy);
    strncpy(substring,string+(pos-1),len);
    // string+(pos-1) --> geeksforgeeks + (6-1) = geeksforgeeks + 5 --> start at 'f' in geeksForgeeks
    printf(substring);

    // Testcase2
    char string2[6] = "abcde";
    char substring2[6];
    
    pos = 1;
    len = 3;
    printf("\nString: %s ", string2);
    printf("\nsubstring is: ");

    // Using strncpy function to 
    // copy the substring
    // strncpy(destination_string, source_string with starting index, lenght of substring we want to copy);
    strncpy(substring2,string2+(pos-1),len);
    //string2+(pos-1) = 6 + (1 - 1) --> 6
    printf(substring2);
    return 0;

    /*
      String: geeksforgeeks 
      substring is: forge
      String: abcde 
      substring is: abc
    */
}

```