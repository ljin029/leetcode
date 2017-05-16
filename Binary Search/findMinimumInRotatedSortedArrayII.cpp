// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : ljin029
// Date   : 2017-05-15

/********************************************************************************** 
* 
* Follow up for "Find Minimum in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* The array may contain duplicates.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach.
 *    1) If nums[left] < nums[right], no rotation in the array, then return nums[left]
 *    2) If nums[left] < nums[right], then there is rotation in the arry, then check
 *    3) If nums[mid] > nums[left], then the rotation is at the second half of the array
 *    4) If nums[mid] < nums[left] it is in the first half of the array
 *    5) Else nums[mid] == nums[left], then duplicates and ++left
 *	6) Time:  O(log n)
 *	7) Space: O(1)
 *
 */

 class Solution {
 public:
	 int findMin(vector<int>& nums) {
		  int left = 0, right = nums.size() - 1;
		  
		  while(left<right){
			  if (nums[left]<nums[right]) return nums[left];
			  int mid = (left+right)/2;
			  if (nums[left]<nums[mid]) left = mid + 1;
			  else if (nums[left]>nums[mid]) right = mid;
			  else ++left;
		  }
		  return nums[left];
		 
	 }
 };

