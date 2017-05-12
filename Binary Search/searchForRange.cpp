// Source : https://oj.leetcode.com/problems/search-for-a-range/
// Author : ljin029
// Date   : 2017-05-11

/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/

/*
 *   O(log n) solution must be something like binary search.
 *   There must be two indices in the array. 
 *   Which means, we can just simply apply to binary search twice to find each index of the target element.
 *
 *   So, we can use the binary search to find the one postion - `pos`
 *   
 *   then, we can keep using the binary search find the target in A[0..pos-1] and A[pos+1..n]
 *
 *   The code below is self-explaination
 */


 class Solution {
 public:
	 vector<int> searchRange(vector<int>& nums, int target) {
		 vector<int> res(2,-1);
		 
		 res[0] = findFirst(nums, target);
		 res[1] = findLast(nums, target);
		 
		 return res;
	 }
	 
	 int findFirst(vector<int>& nums, int target){
		 int idx = -1;
		 int left = 0;
		 int right = nums.size()-1;
		 
		 while (left <= right){
			 int mid = (left+right)/2;
			 if (nums[mid] >= target) right = mid - 1;
			 else left = mid + 1;
			 
			 if (nums[mid] == target)  idx = mid;
		 }
		 return idx;
	 }
	 
	 int findLast(vector<int>& nums, int target){
		 int idx = -1;
		 int left = 0;
		 int right = nums.size()-1;
		 
		 while (left <= right){
			 int mid = (left+right)/2;
			 if (nums[mid] <= target) left = mid + 1;
			 else right = mid - 1;
			 
			 if (nums[mid] == target) idx = mid;
		 }
		 return idx;
	 }	  
 };

