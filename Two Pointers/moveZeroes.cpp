// Source : https://leetcode.com/problems/move-zeroes/
// Author : ljin029
// Date   : 2017-04-28

/*************************************************************************************** 
 *
 * Given an array nums, write a function to move all 0's to the end of it while 
 * maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should
 * be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 ***************************************************************************************/

/*
 *	The solution:
 *	Move non-zero elements to the front of array
 *
 */ 


 class Solution {
 public:
	 void moveZeroes(vector<int>& nums) {
		 for (int i=0,j=0; i<nums.size();++i){
			 // Move non-zero to the front
			 if(nums[i]){
				 swap(nums[i], nums[j]);
				 ++j;
			 }
		 }
	 }
 };

