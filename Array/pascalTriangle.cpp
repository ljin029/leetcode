// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
*               
**********************************************************************************/

/*
 *  The solutioin is to use vector add a new element at the end of vector for each row. 
 *  The midle elements row[j] are the addition of the previous element and row[j] from the previous row
 *
 */

 class Solution {
 public:
	 vector<vector<int>> generate(int numRows) {
		 vector<vector<int>> res;
		 if (numRows<1) return res;
		 vector<int> row(1,1);
		 res.push_back(row);
		 
		 for(int i=2; i<=numRows; ++i){
			 int prev = 1;
			 for(int j=1; j<i-1; ++j){
				 int tmp = row[j];
				 row[j] += prev;
				 prev = tmp;
			 }
			 // Add a new element at the end of row
			 row.push_back(1);
			 res.push_back(row);
		 }
		 return res;
	 }
 };

