// Source : https://oj.leetcode.com/problems/single-number-ii/
// Author : ljin029
// Date   : 2017-03-27

/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0 ;
    int i;
    int common_bit_mask;
    
    for (i=0; i<numsSize; i++)
    {
        // twos gets the bit representation of nums[i]
        twos |= (ones&nums[i]);
        // ones removes the bit representation of nums[i]
        ones ^= nums[i];
        
        // clears the bit representation of num[i] which appreas 3 times
        common_bit_mask = ~(twos&ones);
        
        // removes the bit representatioin of num[i] which appreas 3 times in twos and ones
        twos &= common_bit_mask;
        ones &= common_bit_mask;
    }
    
    return ones;
}


