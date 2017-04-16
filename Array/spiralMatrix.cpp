// Source : https://oj.leetcode.com/problems/spiral-matrix/
// Author : Hao Chen
// Date   : 2014-06-30

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
* 
*               
**********************************************************************************/

/*
 *  The solutioin is just to add the elements in the spiral order.
 *  First the up-most row (u), then the right-most column (r),
 *  then the down-most (d), and finally the left-most column(l).
 *  After finishing a row or a column, update the corresponding row(u or d) or column(l or r)
 *  to continue the process.
 *
 */


 class Solution {
 public:
	 vector<int> spiralOrder(vector<vector<int>>& matrix) {
		 vector<int> ret;
		 if (matrix.empty() || matrix[0].empty()) return ret;
		 int m = matrix.size(); // # of rows
		 int n = matrix[0].size(); // # of cols
		 int u = 0, r = n-1, d = m-1, l = 0, k=0;
		 
		 while(true){
			 // up -> right
			 for(int col=l; col<=r; ++col) ret.push_back(matrix[u][col]);
			 if(++u > d) break;
			 // right -> down
			 for(int row=u; row<=d; ++row) ret.push_back(matrix[row][r]);
			 if(--r < l) break;
			// down -> left
			 for(int col=r; col>=l; --col) ret.push_back(matrix[d][col]);
			 if(--d < u) break;
			// left -> up
			 for(int row=d; row>=u; --row) ret.push_back(matrix[row][l]);
			 if(++l > r) break;
		}
		 return ret;
	 }
 };

