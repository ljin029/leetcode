// Source : https://oj.leetcode.com/problems/rotate-image/
// Author : ljin029
// Date   : 2017-04-16

/********************************************************************************** 
* 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*               
**********************************************************************************/

/*
 *  The solutioin is firstly transpose the matrix and then reverse each row: 
 *  
 *  1 2 3
 *  4 5 6
 *  7 8 9
 *
 *  after transpose:
 *  1 4 7
 *  2 5 8
 *  3 6 9
 *
 *  after reverse:
 *  7 4 1
 *  8 5 2
 *  9 6 3
 *
 */

 class Solution {
 public:
	 void rotate(vector<vector<int>>& matrix) {
		 int n = matrix.size();
		 
		 for(int i=0; i<n; ++i)
		 {
			 for(int j=0; j<i; ++j)
			   swap(matrix[i][j], matrix[j][i]);
		 }
		 
		 for(int i=0; i<n; ++i)
		   reverse(matrix[i].begin(), matrix[i].end());
	 }
 };

