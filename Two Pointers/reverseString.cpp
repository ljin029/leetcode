// Source : https://leetcode.com/problems/reverse-string/
// Author : ljin029
// Date   : 2017-04-28

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and returns the string reversed.
 * 
 * Example:
 * Given s = "hello", return "olleh".
 ***************************************************************************************/

class Solution {
public:
    string reverseString(string s) {
        int j = s.size()-1, i = 0;
        while(i<j){
            swap(s[i++], s[j--]);
        }
        
        return s;
        
    }
}; 

