//Alex Alcazar
//June 8th 2022
//LeetCode Program 1
/*
 * You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.

Return the minimum number of steps to make the given string empty.

A string is a subsequence of a given string if it is generated by deleting some characters of a given string without changing its order. Note that a subsequence does not necessarily need to be contiguous.

A string is called palindrome if is one that reads the same backward as well as forward.



Example 1:

Input: s = "ababa"
Output: 1
Explanation: s is already a palindrome, so its entirety can be removed in a single step.
Example 2:

Input: s = "abb"
Output: 2
Explanation: "abb" -> "bb" -> "".
Remove palindromic subsequence "a" then "bb".
Example 3:

Input: s = "baabb"
Output: 2
Explanation: "baabb" -> "b" -> "".
Remove palindromic subsequence "baab" then "b".


Constraints:

1 <= s.length <= 1000
s[i] is either 'a' or 'b'.
Accepted
101,173

 */
#include <iostream>
#include <vector>

bool isPalindrome(std::string s);
std::string flipString(std::string s);
bool twoLetters(std::string s);


int main() {
    std::string s;

    std::cout << "Enter the word you would like to flip" << std::endl;
    std::cin >> s;
    std::cout << "Your word flipped is "<< flipString(s) << std::endl;
    if(isPalindrome(s))
        std::cout << "Your word is a Palindrome" << std::endl;
    else
        std::cout << "Your word is not a Palindrome" << std::endl;

    if(twoLetters(s))
        std::cout << "Your word contains less than two different letters" << std::endl;
    else
        std::cout << "Your word contains more than two different letters" << std::endl;
    return 0;
}


 bool isPalindrome(std::string s)
{
    std::string wordFlipped = flipString(s);
    if(s==wordFlipped)
        return true;
    else
        return false;
}


std::string flipString(std::string s)
{
    std::string wordFlipped = s;

    //j will start at the end of the given string
    int j = s.length() - 1;

    for(int i= 0; i<s.length()/2; i++)
    {
        //switch letters i and j in the given sequence
        char temp = wordFlipped[i];
        wordFlipped[i] = wordFlipped[j];
        wordFlipped[j] = temp;
        j--;
    }
    return wordFlipped;
}

//checks to see if input contains more than two letters different letters
bool twoLetters(std::string s)
{
    if(s.length()<1)
        return false;

    else
    {
        char a = s[0];
        char b = s[1];

        //ensures there are no more than two letters
        int counter = 0;

        for(int i=1; i<s.length(); i++)
        {
            if(counter==0)
            {
                if(s[i] != a)
                {
                    b = s[i];
                    counter++;
                }
            }
            else
            {
                if(s[i] != a && s[i] != b)
                    return false;
            }
        }
    }

    return true;
}


