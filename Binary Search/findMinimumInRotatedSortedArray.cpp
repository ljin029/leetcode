// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : ljin029
// Date   : 2017-05-15

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach.
 *    1) If nums[left] < nums[right], no rotation in the array, then return nums[left]
 *    2) If nums[left] < nums[right], then there is rotation in the arry, then check
 *    3) If nums[mid] > nums[left], then the rotation is at the second half of the array
 *    4) Else it is in the first half of the array
 *	5) Time:  O(log n)
 *	6) Space: O(1)
 *
 */

 class Solution {
 public:
	 int findMin(vector<int>& nums) {
		 int left = 0, right = nums.size() - 1;
		 
		 while(left<right){
			 if (nums[left]<nums[right]) return nums[left];
			 int mid = (left+right)/2;
			 if (nums[left]<=nums[mid]) left = mid + 1;
			 else right = mid;
		 }
		 
		 return nums[left];
	 }
 };

