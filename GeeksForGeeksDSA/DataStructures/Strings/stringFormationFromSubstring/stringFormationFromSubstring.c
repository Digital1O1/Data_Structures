#include <string.h>
#include <stdio.h>
/*
    Link : https://www.geeksforgeeks.org/problems/string-formation-from-substring2734/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

    Given a string s, the task is to check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

    Example 1:

    Input: s = "ababab"
    Output: 1
    Explanation: It is constructed by
    appending "ab" 3 times
    Example 2:

    Input: s = "ababac"
    Output: 0
    Explanation: Not possible to construct
    Your Task:
    Your task is to complete the function isRepeat() which takes a single string as input and returns 1 if possible to construct, otherwise 0. You do not need to take any input or print anything.

    Expected Time Complexity: O(|s|)
    Expected Auxiliary Space: O(|s|)

    Constraints:
    1 <= |s| <= 105
*/

// Function to determine if the string 's' can be constructed by repeating a substring
int isRepeat(char *s)
{
    int sLength = strlen(s); // Get the length of the original string

    // Loop through possible lengths of the substring
    for (int i = 1; i <= sLength / 2; ++i)
    {
        if (sLength % i == 0)
        {                             // Check if 'i' is a divisor of the total string length
            char subString[i + 1];    // Temporary array to hold the substring
            //char* strncpy( char* dest, const char* src, std::size_t count );
            strncpy(subString, s, i); // Copy the first 'i' characters from 's' to 'subString'
            subString[i] = '\0';      // Null-terminate the substring

            int j;
            // Check if repeating 'subString' forms the entire string 's'
            for (j = i; j < sLength; j += i)
            {
                // Compare the substring with the corresponding part of 's'
                /*
                    Syntax
                    int strncmp( const char* lhs, const char* rhs, size_t count );

                    Parameters 
                    LeftHandSide(lhs), RightHandSide(rhs) - pointers to the possibly null-terminated arrays to compare
                    count    -  maximum number of characters to compare

                    Return value
                    Negative value if lhs appears before rhs in lexicographical order.

                    Zero if lhs and rhs compare equal, or if count is zero.

                    Positive value if lhs appears after rhs in lexicographical order.
                */
                if (strncmp(subString, s + j, i) != 0)
                {
                    break; // If any part doesn't match, break the loop
                }
            }

            // If the loop completes without breaking, the entire string 's' is formed by repeating 'subString'
            if (j == sLength)
            {
                return 1; // Return 1 indicating 's' can be formed by repeating the substring
            }
        }
    }

    return 0; // Return 0 if no valid repeating substring is found
}

int main()
{
    char s[] = "ababab";
    printf("%d\n", isRepeat(s)); // Output: 1 (as "ababab" is formed by repeating "ab")

    char t[] = "ababac";
    printf("%d\n", isRepeat(t)); // Output: 0 (as "ababac" cannot be formed by repeating a substring)

    return 0;
}