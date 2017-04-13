// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* 
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* 
* Your function should return length = 5, and A is now [1,1,2,2,3].
* 
*               
**********************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<3) return nums.size();
        
        int indx = 1;
		// indx is used to track the unduplicates
        for(int i=2; i<nums.size(); ++i)
        {
            if(nums[indx-1] != nums[i]){
                nums[++indx] = nums[i];
            }
        }
        
        return (indx+1);
    }
};


