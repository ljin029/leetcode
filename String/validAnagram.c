// Source : https://leetcode.com/problems/valid-anagram/
// Author : ljin029
// Date   : 2017-04-11

/********************************************************************************** 
 * 
 * Given two strings s and t, write a function to determine if t is an anagram of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *               
 **********************************************************************************/

 #define NO_OF_CHARS 26 // only lowercase 26 alphabets
bool isAnagram(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    if(n != m) return false;
    
    int arr[NO_OF_CHARS] = {0};
    
    int i;
    for(i=0; i<n; ++i)
    {
        ++arr[s[i]-'a'];
    }
    for(i=0; i<m; ++i)
    {
        if (--arr[t[i]-'a']<0)
          return false;
    }
    
    return true;
    
}

