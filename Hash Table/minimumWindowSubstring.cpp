// Source : https://oj.leetcode.com/problems/minimum-window-substring/
// Author : ljin029
// Date   : 2017-06-19

/********************************************************************************** 
* 
* Given a string S and a string T, find the minimum window in S which will 
* contain all the characters in T in complexity O(n).
* 
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
* 
* Minimum window is "BANC".
* 
* Note:
*
* > If there is no such window in S that covers all characters in T, 
*   return the emtpy string "".
* 
* > If there are multiple such windows, you are guaranteed that there 
*   will always be only one unique minimum window in S.
* 
*               
**********************************************************************************/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        int left = 0, count = 0, minLen = s.size()+1;
        int tm[256] = {0}, sm[256] = {0};
        string res ="";
        for (int i=0; i<t.size(); ++i){
            ++tm[t[i]];
        }
        
        // Traverse s
        for(int right=0; right<s.size(); ++right){
            if (tm[s[right]]!=0){
                ++sm[s[right]];
                if(sm[s[right]]<=tm[s[right]]) ++count;
                if(count == t.size()){
                    while (tm[s[left]]==0 || sm[s[left]]>tm[s[left]]){
                        --sm[s[left]];
                        ++left;
                    }
                    if (right-left+1<minLen){
                        minLen = right-left+1;
                        res = s.substr(left, minLen);
                    }
                }
            }
        }
        
        return res;
    }
};


