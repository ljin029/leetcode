// Source : https://oj.leetcode.com/problems/3sum/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a = b = c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
* 
*               
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumFind(nums, 0);
    }
    vector<vector<int>> threeSumFind(vector<int>& nums, int target) {
        vector<vector<int>> findSols;
        if (nums.size()<3) return findSols;
        
        // Sort array and return all triplets not indexes
        sort(nums.begin(), nums.end());
        // Only traverse until the last 3th element for the first element of triplets
        for(int i=0; i<nums.size()-2; i++)
        {
            // skip duplicates
            if ((i>0) && (nums[i] == nums[i-1]))
              continue;
            // use two pointers to traverse between i+1 and the last element
            int left = i+1, right = nums.size()-1;
            while(left<right)
            {
                int curSum = nums[left] + nums[right];
                int curTarget = target - nums[i];
                if (curSum == curTarget)
                {
                    vector<int> sol;
                    // find 3 elements
                    sol.push_back(nums[i]);
                    sol.push_back(nums[left]);
                    sol.push_back(nums[right]);
                    findSols.push_back(sol);
                    ++left, --right;
                    // skip duplicates
                    while(nums[left]==nums[left-1]) ++left;
                    while(nums[right]==nums[right+1]) --right;
                }
                else if (curSum > curTarget){
                    --right;
                    // skip duplicates
                    while(nums[right]==nums[right+1]) --right;
                }
                else {
                    ++left;
                    // skip duplicates
                    while(nums[left]==nums[left-1]) ++left;
                }
            }
        }
        return findSols;
    }

};


