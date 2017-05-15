// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Author : ljin029
// Date   : 2017-05-14

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach.
 *    1) The idea is that when rotating the array, there must be one half of the array that is still in sorted order.
 *    2) If nums[mid] < nums[high], then the right part of array is still in sorted order
 *    3) If nums[mid] > nums[low], then the left part of array is still in sorted order
 *	4) Time:  O(log n)
 *	5) Space: O(1)
 *
 */

 class Solution {
 public:
	 int search(vector<int>& nums, int target) {
		 if (nums.empty()) return -1;
		 int low = 0, high = nums.size() - 1;
		 while(low<=high){
			 int mid = (low+high)/2;
			 if (nums[mid]==target) return mid;
			 else if (nums[mid] < nums[high]){// the right part of array is still in sorted order
				 if (nums[mid] < target && target <= nums[high] ) low = mid + 1;
				 else high = mid - 1;
			 }else{// the left part of array is still in sorted order
				 if (nums[low]<= target && target < nums[mid]) high = mid - 1;
				 else low = mid + 1;
			 }
		 }
		 return -1;
	 }
 };


