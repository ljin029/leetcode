// Source : https://oj.leetcode.com/problems/majority-element/
// Author : ljin029
// Date   : 2017-04-18

/********************************************************************************** 
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 /*
 *  The solution 2 is to Moore Voting Algorithm
 *  Reference: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
 *
 */


 int majorityElement(int* nums, int numsSize) {
	 int res=0,cnt=0;
	 int i;
	 
	 for(i=0; i<numsSize; ++i){
		 if (!cnt){
			 res = nums[i];
			 ++cnt;
		 }else{
			 res==nums[i]?++cnt:--cnt;
			 if(cnt>(numsSize/2)) return res;
		 }
	 }
	 return res;
 }


