// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : ljin029
// Date   : 2017-11-01

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

/*
* Reference: https://www.youtube.com/watch?v=obBdxeCx_Qs
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool p[n][n]={false};
        int maxLen = 1, startPos=0;
        
        for (int i=0; i<n; ++i)
        {
            p[i][i]=true;
            if (s[i]==s[i+1]){
                p[i][i+1]=true;
                maxLen=2;
                startPos=i;
            }
        }

        
        for(int currLen=3; currLen<=n; ++currLen){
            for(int i=0; i<n-currLen+1; ++i){
                int j=i+currLen-1;
                if(s[i]==s[j] && p[i+1][j-1]){
                    p[i][j]=true;
                    maxLen=currLen;
                    startPos=i;
                }
            }
        }
        
        return s.substr(startPos, maxLen);
}
};


