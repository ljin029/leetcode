// Source : https://oj.leetcode.com/problems/unique-paths/
// Author : ljin029
// Date   : 2017-11-08

/********************************************************************************** 
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *    
 *    
 * 
 * How many possible unique paths are there?
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 *               
 **********************************************************************************/

/*
 * Dynamic Programming
 *
 * We have a dp[i][j] represents  how many paths from [0][0] to hear. So, we have the following DP formuler:
 *
 *    dp[i][j] =  1  if i==0 || j==0        //the first row/column only have 1 uniqe path.
 *             =  dp[i-1][j] + dp[i][j-1]   //the path can be from my top cell and left cell.
 */

 class Solution {
 public:
	 int uniquePaths(int m, int n) {
		 vector<vector<int>> dp(m,vector<int>(n, 1));
		 
		 for(int i=1; i<m; ++i)
		 {
			 for(int j=1; j<n; ++j)
			 {
				 dp[i][j] = dp[i-1][j] + dp[i][j-1]; // up + left
			 }
		 }
		 return dp[m-1][n-1];
	 }
 };

