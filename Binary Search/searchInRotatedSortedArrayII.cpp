// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : ljin029
// Date   : 2017-05-14

/********************************************************************************** 
* 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Write a function to determine if a given target is in the array.
*               
**********************************************************************************/

/*
 *	The solution:
 *	Binary search approach.
 *    1) The idea is that when rotating the array, there must be one half of the array that is still in sorted order.
 *    2) If nums[mid] < nums[high], then the right part of array is still in sorted order
 *    3) If nums[mid] > nums[low], then the left part of array is still in sorted order
 *    4) If nums[mid] == nums[high], then --high
 *	5) Time:  O(log n)
 *	6) Space: O(1)
 *
 */

 class Solution {
 public:
	 bool search(vector<int>& nums, int target) {
		  if (nums.empty()) return false;
		  int low = 0, high = nums.size() - 1;
		  while(low<=high){
			  int mid = (low+high)/2;
			  if (nums[mid]==target) return true;
			  else if (nums[mid] < nums[high]){// the right part of array is still in sorted order
				  if (nums[mid] < target && target <= nums[high] ) low = mid + 1;
				  else high = mid - 1;
			  }else if (nums[mid] > nums[high]){// the left part of array is still in sorted order
				  if (nums[low]<= target && target < nums[mid]) high = mid - 1;
				  else low = mid + 1;
			  }else --high;
		  }
		  return false;
		 
	 }
 };


