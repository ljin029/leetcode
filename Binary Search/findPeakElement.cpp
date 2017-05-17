// Source : https://oj.leetcode.com/problems/find-peak-element/
// Author : ljin029
// Date   : 2017-05-16

/********************************************************************************** 
* 
* A peak element is an element that is greater than its neighbors.
* 
* Given an input array where num[i] ? num[i+1], find a peak element and return its index.
* 
* You may imagine that num[-1] = num[n] = -8.
* 
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* 
* click to show spoilers.
* 
* Note:
* Your solution should be in logarithmic complexity.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach.
 *    1) If nums[mid] < nums[mid+1], then the peak on the right
 *    2) If nums[mid] >= nums[mid+1], then the peak on the left
 *	3) Time:  O(log n)
 *	4) Space: O(1)
 *
 */

 class Solution {
 public:
	 int findPeakElement(vector<int>& nums) {
		 int left = 0, right = nums.size() - 1;
		 
		 while(left<right){
			 int mid = (left+right)/2;
			 if (nums[mid] < nums[mid+1]) left = mid + 1;
			 else right = mid;
		 }
		 
		 return right;
	 }
 };


