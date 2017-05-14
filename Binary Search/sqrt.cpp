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
 *	Binary search approach.
 *	2) Time:  O(log n)
 *	3) Space: O(1)
 *
 */

 class Solution {
 public:
	 int mySqrt(int x) {
		 if (!x) return 0;
		 
		 int low = 1, high = x;
		 int res;
		 while (low<=high){
			 int mid = (low+high)/2;
			 if (mid <= x/mid) {
				 low = mid + 1;
				 res = mid;
			 }
			 else high = mid - 1;
		 }
		 
		 return res;
	 }
 };

