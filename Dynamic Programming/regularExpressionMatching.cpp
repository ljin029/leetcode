// Source : https://oj.leetcode.com/problems/regular-expression-matching/
// Author : ljin029
// Date   : 2017-11-07

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") ? false
* isMatch("aa","aa") ? true
* isMatch("aaa","aa") ? false
* isMatch("aa", "a*") ? true
* isMatch("aa", ".*") ? true
* isMatch("ab", ".*") ? true
* isMatch("aab", "c*a*b") ? true
* 
*               
**********************************************************************************/

/*
* Reference: https://www.youtube.com/watch?v=l3hda49XcDE&index=7&t=968s&list=PLJiEKUZhFmaouv7jKOAunGQm-PzkdpFzT
*/

class Solution {
public:
    bool isMatch(string s, string p) {         
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0]=true;
        for (int i=0; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(j>1 && p[j-1]=='*'){                    
                    dp[i][j] =  (dp[i][j-2]) || (i>0 && dp[i-1][j]&&(s[i-1]==p[j-2] || p[j-2]=='.'));
                }else{
                    dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                }
            }
        }
        return dp[m][n];
    }
};

