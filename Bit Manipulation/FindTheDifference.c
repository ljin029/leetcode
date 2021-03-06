// Source : https://leetcode.com/problems/find-the-difference/
// Author : ljin029
// Date   : 2017-03-28

/*************************************************************************************** 
 *
 * Given two strings s and t which consist of only lowercase letters.
 * 
 * String t is generated by random shuffling string s and then add one more letter at a 
 * random position.
 * 
 * Find the letter that was added in t.
 * 
 * Example:
 * 
 * Input:
 * s = "abcd"
 * t = "abcde"
 * 
 * Output:
 * e
 * 
 * Explanation:
 * 'e' is the letter that was added.
 ***************************************************************************************/
 char findTheDifference(char* s, char* t) {
    int len = strlen(s);
    int i;
    
    char ch = t[len];
    
    for (i=0; i<len; i++)
    {
        ch ^= s[i];
        ch ^= t[i];
    }
    
    return ch;
}

