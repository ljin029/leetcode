// Source : https://oj.leetcode.com/problems/palindrome-partitioning-ii/
// Author : ljin029
// Date   : 2017-10-30

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return the minimum cuts needed for a palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
* 
*               
**********************************************************************************/

/*
* Reference: https://www.youtube.com/watch?v=WPr1jDh3bUQ&t=313s&index=1&list=PLJiEKUZhFmaouv7jKOAunGQm-PzkdpFzT
* String s is palindrom if
* 1) First and last characters should match
* 2) Substring is palindrom
*
* Construct palindrome table p[n][n]
* 1) single character is plindrom p[i][i] = true
* 2) check two ajacent characters if p[i][i+1] = true
* 3) check the length of characters is palindrome if s[i]==s[j] && p[i+1][j-1], where 3 <= length < n
*
* Construct 1D cuts[n]
* cuts[i] = min(cuts[i], 1+cuts[j]) iff p[j+1][i]==true, where 0<=j<i, 0<=i<n;
* return cuts[n-1]
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool p[n][n];
        int cuts[n]={0};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                p[i][j] = false;
            }
        }        
        /* Trivial case: one single character */
        for (int i=0; i<n; ++i)
        {
            p[i][i] = true;
        }
        
        /* Finding palindrom of two adjacent characters */
        for (int i=0; i<n-1; ++i)
        {
            if(s[i]==s[i+1])
            {
                p[i][i+1] = true;
            }
        }
        
        /* Finding palindromes of length 3 - n */
        for(int curr_len=3; curr_len<=n; ++curr_len)
        {
            for(int i=0; i<n-curr_len+1; ++i)
            {
                int j = i + curr_len -1;
                if (s[i]==s[j] && p[i+1][j-1])
                {
                    p[i][j]=true;
                }
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            cuts[i]=INT_MAX;
            if(p[0][i])
            {
                cuts[i]=0;
            }
            else{
				
                for(int j=0; j<i; ++j)
                {
                    if(p[j+1][i])
                    {
                        cuts[i] = min(cuts[i], 1 + cuts[j]);
                    }
                }
            }
        }

        return cuts[n-1];
    }
};

