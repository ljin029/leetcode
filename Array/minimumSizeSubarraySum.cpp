// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : ljin029
// Date   : 2017-04-18

/********************************************************************************** 
 * 
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray 
 * of which the sum = s. If there isn't one, return 0 instead.
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 /*
  * Sliding window solution for O(n) solution. It is required to find the contiguous subarray so that two pointers were used
  * to track the subarray as sliding window. The "right" pointer was used to track the sum which is < s. The "left" pointer was
  * used to track the sum which is >= s. The minimal length of a contiguous subarray will be found until
  * the "right" or/and "left" pointer reaches the boundary.
  * 
  * Edge case:
  * 1) There isn’t exist a subarray which the sum will larger than s.
  * 2) When right reach the last index of array, the left index should still keep moving if the sum is larger than s. But when stop?!
  * 3) When there exist an element which is equal or larger than s.
  *
  * Time: O(n)
  * Space: O(1)
  */

 class Solution {
 public:
	 int minSubArrayLen(int s, vector<int>& nums) {
		 if (nums.size()==0) return 0;
		 
		 int left=0, right=0, res=nums.size()+1, sum=0;
		 while(right<nums.size()){
			 sum += nums[right++];
			 while(sum>=s && left<nums.size()){
				 res = min(res, right-left);
				 sum -= nums[left++];
			 }
		 }
		 
		 return res==(nums.size()+1)?0:res;
	 }
 };



