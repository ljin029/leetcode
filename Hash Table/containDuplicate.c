// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 *               
 **********************************************************************************/

 int cmpfunc (const void * a, const void * b)
 {
	return ( *(int*)a - *(int*)b );
 }
 
 bool containsDuplicate(int* nums, int numsSize) {
	 qsort(nums, numsSize, sizeof(int), cmpfunc);
	 int i;
	 for (i=1; i<numsSize; i++)
	 {
		 if (nums[i] == nums[i-1])
		   return true;
	 }
	 
	 return false;
 }

