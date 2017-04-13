// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Given a sorted array, remove the duplicates in place such that each element appear 
* only once and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* 
* For example,
* Given input array A = [1,1,2],
* 
* Your function should return length = 2, and A is now [1,2].
* 
*               
**********************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        
        int indx = 0;
        for(int i=1; i<nums.size(); ++i)
        {
            if(nums[indx] != nums[i]){
                ++indx;
                if (i!=indx){
                    nums[indx] = nums[i];
                }
            } 
        }
        
        return (indx+1);
    }
};


