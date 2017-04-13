// Source : https://oj.leetcode.com/problems/4sum/
// Author : ljin029
// Date   : 2017-04-12

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note:
* 
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a = b = c = d)
* The solution set must not contain duplicate quadruplets.
* 
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* 
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
* 
*               
**********************************************************************************/

/********************************************************************************** 
* 
* This solution provides the way to solve the k-Sum using recursion.
* 4-Sum is based on 3-Sum and 3-Sum is based on 2-Sum and so on.
*
*               
**********************************************************************************/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> findSol;
        vector<int> sol;
        
        sort(nums.begin(), nums.end());
        kSum(nums, 0, nums.size()-1, target, 4, sol, findSol);
        return findSol;
    }
    
    void kSum(vector<int> &nums, int start, int end, int target, int k, vector<int> &sol, vector<vector<int>> &findSol){
        if (k<=0) return;
        if (k==1){
            for(int i=start; i<=end; ++i){
                if (target == nums[i]){
                    sol.push_back(target);
                    findSol.push_back(sol);
                    sol.pop_back();
                    return; 
                }
            }
        }
        
        if (k==2){
            twoSum(nums, start, end, target, sol, findSol);
            return;
        }
        for(int i=start; i<=end-(k-1);++i){
            
            if(i>start && nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            kSum(nums, i+1, end, target-nums[i], k-1, sol, findSol);
            sol.pop_back();
        }
    }
    
    void twoSum(vector<int>& nums, int start, int end, int target, vector<int>& sol, vector<vector<int>>& findSol){
        // Use two pointers to traverse the input array
        while(start<end){
            int sum = nums[start] + nums[end];
            if (sum == target){
                sol.push_back(nums[start]);
                sol.push_back(nums[end]);
                findSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                ++start, --end;
                while(nums[start]==nums[start-1]) ++start;
                while(nums[end]==nums[end+1]) --end;
            }else if (sum < target){
                ++start;
                while(nums[start]==nums[start-1]) ++start;
            }else{
                --end;
                while(nums[end]==nums[end+1]) --end;
            }
        }
    }
};


