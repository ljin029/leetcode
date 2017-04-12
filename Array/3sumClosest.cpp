// Source : https://oj.leetcode.com/problems/3sum-closest/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is 
* closest to a given number, target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3) return INT_MAX;
        
        // Sort input array
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for(int i=0; i<nums.size()-2; ++i)
        {
            // use two pointer to traverse the sorted array
            int left = i+1, right = nums.size()-1;
            while(left<right)
            {
                int diff = nums[i] + nums[left] + nums[right] - target;
                if (abs(diff) < abs(minDiff)){
                    minDiff = diff;
                }
                if (diff>0) --right;
                else if (diff<0) ++left;
                else break;
            }
        }
        return (target+minDiff);
    }
};


