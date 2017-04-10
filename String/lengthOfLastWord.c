// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : ljin029
// Date   : 2017-04-10

/********************************************************************************** 
* 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
* 
*               
**********************************************************************************/

int lengthOfLastWord(char* s) {
    int len = 0;
    
    while (*s)
    {
        if (*s++ != ' ')
        {
            ++len;
        }
        else if (*s && *s != ' ')
        {
            len = 0;
        }
    }
    
    return len;
}


