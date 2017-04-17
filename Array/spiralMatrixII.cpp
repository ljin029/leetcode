// Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
// Author : ljin029
// Date   : 2017-04-16

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret( n, vector<int>(n) );
        int mult = n * n;
        int u = 0, r = n-1, d = n-1, l = 0, k=1;
        
        while(k<=mult){
            // up -> right
            for(int col=l; col<=r; ++col) ret[u][col]=k++;
            ++u;
            // right -> down
            for(int row=u; row<=d; ++row) ret[row][r]=k++;
            --r;
            // down -> left
            for(int col=r; col>=l; --col) ret[d][col]=k++;
            --d;
            // left -> up
            for(int row=d; row>=u; --row) ret[row][l]=k++;
            ++l;
        }
        return ret;
    }
};

