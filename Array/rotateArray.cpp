// Source : https://leetcode.com/problems/rotate-array/
// Author : ljin029
// Date   : 2017-04-18

/********************************************************************************** 
* 
* Rotate an array of n elements to the right by k steps.
* For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
* 
* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* 
* Hint:
* Could you do it in-place with O(1) extra space?
* 
* Related problem: Reverse Words in a String II
* 
* Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*               
**********************************************************************************/


/*
 * this solution is so-called three times rotate method
 * because (X^TY^T)^T = YX, so we can perform rotate operation three times to get the result
 * obviously, the algorithm consumes O(1) space and O(n) time
 */

 class Solution {
 public:
	 void rotate(vector<int>& nums, int k) {
		 int n = nums.size();
		 k %= n;
		 
		 // first reverse the first n-k elements
		 reverse(nums.begin(), nums.begin()+(n-k));
		 // reverse the last k elements
		 reverse(nums.begin()+(n-k), nums.end());
		 // reverse the entire of array
		 reverse(nums.begin(), nums.end());
	 }
 };

