// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : ljin029
// Date   : 2017-08-22

/********************************************************************************** 
* 
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*               
**********************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i=0; i<s.size();++i){
            if (m[s[i]] ==0 || m[s[i]] <left){
                res = max(res, i-left+1);
            }
            else{
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        
        return res;
    }
};


