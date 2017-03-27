// Source : https://oj.leetcode.com/problems/single-number/
// Author : ljin029
// Date   : 2017-03-27

/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

int singleNumber(int* nums, int numsSize) {
    int res, i;
    
    for (i=0; i<numsSize; i++)
    {
        res ^= nums[i];
    }
    
    return res;
}

