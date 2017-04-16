// Source : https://oj.leetcode.com/problems/first-missing-positive/
// Author : ljin029
// Date   : 2017-04-16

/********************************************************************************** 
* 
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
*                
**********************************************************************************/

/*
 *  Traverse the array: 
 *
 *  1. If nums[i]<1 or nums[i]>n, then nums[i] is not the first missing postive, and skip it 
 *  2. If nums[i]=i+1, then nums[i] is put in the right place
 *  3. If nums[i]!=nums[nums[i]-], and 0<nums[i]<=n, swap the value of nums[nums[i]-1] with nums[i]
 *  4. If nums[i]=nums[nums[i]-1], it will go infinite loop so that skip the case
 *
 */


 class Solution {
 public:
	 int firstMissingPositive(vector<int>& nums) {
		 int n = nums.size();
		 
		 int i = 0;
		 while(i<n){
			 if (nums[i]!= (i+1) && nums[i]<=n && nums[i]>0 && nums[i]!=nums[nums[i]-1] )
			   swap(nums[i], nums[nums[i]-1]);
			 else ++i;
		 }
		 for(i=0; i<n; ++i){
			 if(nums[i]!=(i+1)) return i+1;
		 }
		 return n+1;
	 }
 };

