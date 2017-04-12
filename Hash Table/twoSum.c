// Source : https://oj.leetcode.com/problems/two-sum/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    if (numsSize<2) return NULL;
    int* res = (int*) malloc(2*sizeof(int));
    
    memset(res, 0, 2);
    int i,j;
    for(i=0; i<numsSize; ++i)
    {
        for(j=i+1; j<numsSize; ++j)
        {
            if(target-nums[i] == nums[j]){
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }
        
    return res;
}


