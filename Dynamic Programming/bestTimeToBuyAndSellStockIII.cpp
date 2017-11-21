// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : ljin029
// Date   : 2017-11-20

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
* 
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*               
**********************************************************************************/

/*
** dp[i][j] represents the max profit up until prices[j] and i is the number of transaction
** dp[i][j] = max (dp[i][j-1], prices[j]-prices[m]+dp[i][m]) for m=[0...j-1];
** Hence, tmpMax = max(tmpMax, dp[i][m]-prices[m]) for m=[0...j-1];
** dp[i][j] = max (dp[i][j-1], prices[j]+tmpMax);
** maxProf=max(maxProf, dp[i][j]);
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), kk = 2;
        if (n<=1) return 0;
        vector<vector<int>> dp(kk+1,vector<int>(n, 0));
        
        int maxProf=0;
        for(int i=1; i<=kk; ++i){
            int tmpMax = dp[i][0]-prices[0];
            for(int j=1; j<n; ++j){
                dp[i][j]=max(dp[i][j-1], prices[j]+tmpMax);
                tmpMax=max(tmpMax, dp[i-1][j]-prices[j]);
                maxProf=max(maxProf, dp[i][j]);
            }
        }
        return maxProf;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy1=INT_MIN, buy2=INT_MIN;
        int sell1=0, sell2=0;

        for(int i=0; i<n; ++i){
            sell2=max(sell2, buy2+prices[i]);
            buy2=max(buy2, sell1-prices[i]);
            sell1=max(sell1, buy1+prices[i]);
            buy1=max(buy1, -prices[i]);
        }
        
        return sell2;
    }
};



