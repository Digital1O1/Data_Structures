#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHAR = 26;

// function to return count of palindromic sub-string
int countPalindrome(string str)
{
    // n = 11
    int n = str.size();
    int sum = 0;

    // initialize frequency table as an array with 0
    // int hashTable[11] = {0};
    int hashTable[MAX_CHAR] = {0};

    /*
        calculate frequency
        Remember 'a' == 97, we're doing this so we can get values of 1 - 25 in the hashTable

        Taking the second letter 'n' from the given string
            - 'n' ASCII value == 110
            - 'a' ASCII value == 97
            - 110 - 97 = 13
            - hashTable[13]++ will be incremented so the next position is reserved for the letter 'n'
            - The result of str[i] - 'a' gives the index corresponding to the position of the letter in the alphabet
                - 'a' corresponds to index 0,
                - 'b' corresponds to index 1,
                - 'n' corresponds to index 13
    */
    for (int i = 0; i < n; i++)
    {
        std::cout << "Iteration counter : " << i << "Hash value : " << hashTable[str[i] - 'a']++ << std::endl;
    }

    for (int i = 0; i < 26; i++)
    {

        /*
            Notes about the formula used
                - Substring of lenght 1
                    - Every individual occurence of a character is a palindromic substring
                    - Characters appearing 'k' times contributes 'k' palindromic substrings
                        - Each occurrence of the character is a palindrome
                - Substrings of length 2
                    - Any pair of consecutive occurrences of the character will form a palindromic substring
                    - The number of such substrings is the number of ways you can pick 2 characters from k occurrences
                    - This is 'k'
                    - Or choose 2 or (k  2) which is calculated as
                        - (k 2) = [ k * (k-1)/2]
                - Substrings of length 3, 4, ..., k:
                    - Larger palindromic substrings can also be formed if the character repeats multiple times.
                    - For example, if a character appears 3 times consecutively, you get a palindromic substring of length 3.

            Example to clarify

            - Suppose the letter 'a' appears 4 times in the string.
            - For substrings of length 1 (each individual occurrence of 'a'):
                - We have 4 such substrings: ['a', 'a', 'a', 'a'].
            - For substrings of length 2 (any pair of consecutive 'a's):
                - We can form 3 such substrings: ['aa', 'aa', 'aa'].
            - For substrings of length 3:
                - We can form 2 such substrings: ['aaa', 'aaa'].
            - For substrings of length 4:
                - We can form 1 such substring: ['aaaa'].
            - So the total number of palindromic substrings formed by the letter 'a' sppearing 4 times is
                - 1 + 2 + 3 + 4 = [ (4 * ( 4 + 1) / 2 ) ]  10

            The general formula
                - For 'k' occurrences of a character, the total number of palindromic substrings is
                -   k * (k + 1) / 2
                - The second for loop calcualtes this value for EACH chracter based on it's frequency and adds it to the total sum

            Why this formula works
                - If a character appears k times, every occurrence of the character is a palindromic substring of length 1.
                - You can form additional palindromic substrings by combining consecutive occurrences of the character to form longer palindromes (like aa, aaa, etc.).
                - The formula sums up all possible palindromic substrings for each character by calculating all the combinations of substrings formed by k occurrences of that character.
        */
        if (hashTable[i])
            sum += (hashTable[i] * (hashTable[i] + 1) / 2);
        std::cout << "Sum : " << sum << std::endl;
    }

    // return result
    return sum;
}

// driver program
int main()
{
    string str = "abdbca";

    std::cout << countPalindrome(str);
    return 0;
}

/*
    Example i = 1

    hashTable[str[2] - 'a']++ --> hashTable[str[n] - 'a'] ++ --> hashTable[110 - 95]++ --> hashTable[15]
*/
