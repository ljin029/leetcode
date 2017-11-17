// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
*
* Example 1:
* Input: [7, 1, 5, 3, 6, 4]
* Output: 5

* max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
*
* Example 2:
* Input: [7, 6, 4, 3, 1]
* Output: 0

* In this case, no transaction is done, i.e. max profit = 0.
*               
**********************************************************************************/

/*
 *  The solutioin is required to make the day of selling later than the one of buying.
 *  Use minPrice as maker:
 *  If prices[i] < minPrice, then minPrice = prices[i] and cannot sell the stock at the same day
 *  If prices[i] > minPrice, then it may be the best day to sell the stock and compare (prices[i]-minPrice)
 *  with the current max profit.
 *
 */


 class Solution {
 public:
	 int maxProfit(vector<int>& prices) {
		 if (prices.empty()) return 0;
		 int buy=prices[0], sell=0;
		 
		 for(int i=1; i<prices.size(); ++i){
			 buy = min(buy, prices[i]);
			 sell = max(sell, prices[i]-buy);
		 }
		 return sell;
	 }
 };

