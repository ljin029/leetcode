// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : ljin029
// Date   : 2017-05-14

/********************************************************************************** 
* 
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach: For non-negative n, its sqrt <= x/2+1, search in the range (0, x/2+1]
 *	1) Time:  O(log n)
 *	2) Space: O(1)
 *
 */

 class Solution {
 public:
	 int mySqrt(int x) {
		 long long i=0, j=x/2+1;
		 
		 while (i<=j)
		 {
			 long long mid = (i+j)/2;
			 long long sqrt=mid * mid;
			 if (sqrt==x) return mid;
			 else if (sqrt<x) i=mid+1;
			 else j=mid-1;
		 }
		 return j;
	 }
 };

