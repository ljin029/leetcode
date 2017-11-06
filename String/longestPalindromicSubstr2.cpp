// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : ljin029
// Date   : 2017-11-05

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

/*
* Reference: http://www.cnblogs.com/love-yh/p/7072161.html
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int right=0, mi=0, maxLen=0, maxPoint=0;
        
        string res="$#";
        for(int i=0; i<n; ++i)
        {
            res+=s[i];
            res+="#";
        }
        
        vector<int> p(res.size(), 0);
        for(int i=1; i<res.size(); ++i)
        {
            p[i]= right>i?min(p[2*mi-i], right-i):1;
            
            while(res[i+p[i]]==res[i-p[i]]) ++p[i];
            
            if(right<i+p[i])
            {
                right=i+p[i];
                mi=i;
            }
            if(maxLen<p[i])
            {
                maxLen=p[i];
                maxPoint=i;
            }
        }
        
        return s.substr((maxPoint-maxLen)/2, maxLen-1);
    }
};

