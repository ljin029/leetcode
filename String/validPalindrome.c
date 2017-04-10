// Source : https://oj.leetcode.com/problems/valid-palindrome/
// Author : ljin029
// Date   : 2017-04-10

/********************************************************************************** 
* 
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
* 
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* 
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* 
* For the purpose of this problem, we define empty string as valid palindrome.
* 
*               
**********************************************************************************/

bool isPalindrome(char* s) {
    
    int left = 0, right = strlen(s)-1;
    
    while (left<right)
    {
        if (!isalnum(s[left])) ++left;
        else if (!isalnum(s[right])) --right;
        else if ((s[left] + 32 - 'a')%32 != (s[right] + 32 - 'a')%32) return false;
        else{
            ++left; --right;
        }
    }
    
    return true;
}


