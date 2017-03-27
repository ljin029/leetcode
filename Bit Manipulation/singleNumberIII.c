// Source : https://leetcode.com/problems/single-number-iii/
// Author : ljin029
// Date   : 2017-3-27

/*************************************************************************************** 
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and 
 * all the other elements appear exactly twice. Find the two elements that appear only 
 * once.
 * 
 * For example:
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is also 
 * correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using 
 * only constant space complexity?
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 ***************************************************************************************/
 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i;
    int res=0;
    
    for (i=0; i<numsSize; i++)
    {
        res ^= nums[i];
    }
    
    /* n & (n - 1) unset the lower set bit of n
       in binary: XXX10000 -> XXX00000
       (n & (n -1)) ^ n get the last bit 1 of n
       */
    res = (res & (res-1)) ^ res;
    *returnSize = 2;
    int *ret = (int*)malloc(*returnSize * sizeof(int));
    if (ret)
    {
        ret[0] = 0;
        ret[1] = 0;
        for (i=0; i<numsSize; i++)
        {
            if ( res & nums[i] )
            {
                ret[0] ^=  nums[i];
            }
            else
            {
                ret[1] ^=  nums[i];
            }
        }
    }  

    return ret;
}

