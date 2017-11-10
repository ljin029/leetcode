// Source : https://oj.leetcode.com/problems/decode-ways/
// Author : ljin029
// Date   : 2017-11-10

/********************************************************************************** 
* 
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* 
* Given an encoded message containing digits, determine the total number of ways to decode it.
* 
* For example,
* Given encoded message "12",
* it could be decoded as "AB" (1 2) or "L" (12).
* 
* The number of ways decoding "12" is 2.
* 
*               
**********************************************************************************/

/*
** Reference: https://www.youtube.com/watch?v=aCKyFYF9_Bg
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n==0) return 0;
        vector<int> dp(n+1, 0);
        
        dp[0]=1;
        dp[1]=s[0]!='0'?1:0;
        for(int i=2; i<=n; ++i)
        {
            dp[i] = s[i-1] != '0'? dp[i-1]:0;            
            if (s[i-2]=='1' || s[i-2]=='2'&&s[i-1]<='6')
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

