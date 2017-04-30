// Source : https://leetcode.com/problems/find-the-duplicate-number/
// Author : ljin029
// Date   : 2017-04-29

/*************************************************************************************** 
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and 
 * n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * > You must not modify the array (assume the array is read only).
 * > You must use only constant, O(1) extra space.
 * > Your runtime complexity should be less than O(n2).
 * > There is only one duplicate number in the array, but it could be repeated more than
 *   once.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test
 * cases.
 *               
 ***************************************************************************************/

/*
 *	The solution:
 *	1) Two pointers method, same as Linked List Cycle II.
 *	2) Time:  O(n)
 *	3) Space: O(1)
 *
 */

 class Solution {
 public:
	 int findDuplicate(vector<int>& nums) {
		 int slow = 0, fast = 0;
		 while(true){
			 slow = nums[slow];
			 fast = nums[nums[fast]];
			 if (slow == fast) break;
		 }
		 fast = 0;
		 while(true){
			 slow = nums[slow];
			 fast = nums[fast];
			 if (slow == fast) break;
		 }
		 
		 return slow;
	 }
 };

 /*
  *  The solution:
  *  1) Binary search method
  *  2) Time:  O(n log n)
  *  3) Space: O(1)  
  *
  */

 class Solution {
 public:
	 int findDuplicate(vector<int>& nums) {
		 int low = 0, high = nums.size() - 1, mid;
		 
		 while (low<high){
			 mid = (low + high)/2;
			 int cnt=0;
			 for(auto t : nums){
				 if (t<=mid) ++cnt;
			 }
			 if (cnt<=mid) low = mid + 1;
			 else high = mid;
		 }
		 return low;
	 }
 };

