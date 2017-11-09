// Source : https://oj.leetcode.com/problems/scramble-string/
// Author : ljin029
// Date   : 2017-11-09

/********************************************************************************** 
* 
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* 
* Below is one possible representation of s1 = "great":
* 
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
* 
* To scramble the string, we may choose any non-leaf node and swap its two children.
* 
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
* 
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
* 
* We say that "rgeat" is a scrambled string of "great".
* 
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
* 
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
* 
* We say that "rgtae" is a scrambled string of "great".
* 
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
* 
*               
**********************************************************************************/

/*
* Reference: https://discuss.leetcode.com/topic/36715/simple-iterative-dp-java-solution-with-explanation
*/

/**
* Let F(i, j, k) = whether the substring S1[i..i + k - 1] is a scramble of S2[j..j + k - 1] or not
* Since each of these substrings is a potential node in the tree, we need to check for all possible cuts.
* Let q be the length of a cut (hence, q < k), then we are in the following situation:
* 
* S1 [   x1    |         x2         ]
*    i         i + q                i + k - 1
* 
* here we have two possibilities:
*      
* S2 [   y1    |         y2         ]
*    j         j + q                j + k - 1
*    
* or 
* 
* S2 [       y1        |     y2     ]
*    j                 j + k - q    j + k - 1
* 
* which in terms of F means:
* 
* F(i, j, k) = for some 1 <= q < k we have:
*  (F(i, j, q) AND F(i + q, j + q, k - q)) OR (F(i, j + k - q, q) AND F(i + q, j, k - q))
*  
* Base case is k = 1, where we simply need to check for S1[i] and S2[j] to be equal 
* */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));
        for (int k=1; k<=n; ++k)
            for (int i=0; i+k <= n; ++i)
                for (int j=0; j+k <=n; ++j){
                    if (k==1) dp[i][j][k] = s1[i]==s2[j];
                    else for (int q=1; q<k && !dp[i][j][k]; ++q){
                        dp[i][j][k]=dp[i][j][q] && dp[i+q][j+q][k-q] || dp[i][j+k-q][q] && dp[i+q][j][k-q];
                    }
                }
        
        return dp[0][0][n];
        
    }
};

