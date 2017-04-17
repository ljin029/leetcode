// Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Given an index k, return the kth row of the Pascal's triangle.
* 
* For example, given k = 3,
* Return [1,3,3,1].
* 
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
**********************************************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1,1); // indx=0, start row 0, 1, 2...
        if (rowIndex<1) return res;
        
        // Start from the 1st row
        for(int i=1; i<rowIndex+1; ++i){
            int prev = 1;
            for(int j=1; j<i; ++j){
                int tmp = res[j];
                res[j] += prev;
                prev = tmp;
            }
            res.push_back(1);
        }
        return res;
    }
};


