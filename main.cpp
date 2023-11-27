//Alex Alcazar
//June 8th 2022
//LeetCode Remove palindromic subsequence

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


