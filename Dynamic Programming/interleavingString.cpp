// Source : https://oj.leetcode.com/problems/interleaving-string/
// Author : ljin029
// Date   : 2017-11-15

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/

/*
** Reference: https://www.youtube.com/watch?v=ih2OZ9-M3OM
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) return false;
        int n1=s1.size(), n2=s2.size();
        
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        
        for(int i=0; i<=n1; ++i){
            for(int j=0; j<=n2; ++j){
                if (i==0 && j==0) dp[i][j]=true;
                else if (i==0){
                    dp[i][j] = dp[i][j-1]&&s2[j-1]==s3[i+j-1];
                }else if (j==0){
                    dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i+j-1];
                }else{
                    dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i+j-1] || dp[i][j-1]&&s2[j-1]==s3[i+j-1];
                }                    
            }
        }
        return dp[n1][n2];
    }
};


