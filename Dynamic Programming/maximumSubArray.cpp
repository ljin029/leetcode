// Source : https://oj.leetcode.com/problems/maximum-subarray/
// Author : ljin029
// Date   : 2017-11-08

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
* the contiguous subarray [4,-1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/

/*
* Reference: http://codercareer.blogspot.ca/2011/09/no-03-maximum-sum-of-all-sub-arrays.html
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[0]=nums[0];
        int maxSum=dp[0];
        for(int i=1; i<n; ++i)
        {
            dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0);
            maxSum=max(dp[i], maxSum);
        }
        
        return maxSum;
    }
};

