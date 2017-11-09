// Source : https://oj.leetcode.com/problems/climbing-stairs/
// Author : ljin029
// Date   : 2017-11-08

/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*               
**********************************************************************************/

/*
 * Reference: https://www.youtube.com/watch?v=CFQk7OQO_xM
 */

 class Solution {
 public:
	 int climbStairs(int n) {
		 if (n<=1) return 1;
		 vector<int> dp(n,0);
		 
		 // 1 stair and 2 stairs
		 dp[0]=1, dp[1]=2;
		 
		 // n>=2
		 for(int i=2; i<n; ++i)
		 {
			 dp[i]=dp[i-1]+dp[i-2];
		 }
		 
		 return dp[n-1];
	 }
 };


