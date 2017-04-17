// Source : https://oj.leetcode.com/problems/set-matrix-zeroes/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* 
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* 
*               
**********************************************************************************/

/*
 *  The solutioin is required to use O(1) space so that the first row and col are used as marker
 *  1) Scan the whole matrix, and set matrix[i][0]=0 and matrix[0][j]=0 if matrix[i][j]=0
 *  2) Based on the outcome 1), set firstRowZero=true if i=0 or set firstColZero=true if j=0
 *  3) Scan the matrix from the row 1~m-1 and the col 1~n-1, set the entire the ith row to zero if matrix[i][0]=0
 *  4) Scan the matrix from the row 1~m-1 and the col 1~n-1, set the entire the jth col to zero if matrix[0][j]=0
 *  5) Set the first row to zero if firstRowZero=true
 *  6) Set the frist col to zero if firstColZero=true
 *
 */


 class Solution {
 public:
	 void setZeroes(vector<vector<int>>& matrix) {
		 if (matrix.size()==0 || matrix[0].size()==0) return;
		 
		 int m = matrix.size(), n = matrix[0].size();
		 bool firstRowZero = false, firstColZero = false;
		 
		 // Scan the whole matrix and set matrix[i][0]=0 and matrix[0][j]=0 if matrix[i][j]=0
		 for(int i=0; i<m; ++i){
			 for(int j=0; j<n; ++j){
				 if(matrix[i][j]==0){
					 matrix[i][0]=0;
					 matrix[0][j]=0;
					 if(i==0) firstRowZero=true;
					 if(j==0) firstColZero=true;
				 }
			 }
		 }
		 // Scan the matrix from the row 1~m-1 and the col 1~n-1 and set the entire row to zero if matrix[i][0]=0 
		 for(int i=1; i<m; ++i){
			 if(matrix[i][0]==0){
				 for(int j=1; j<n; ++j)
				   matrix[i][j]=0;
			 }
		 }
		 // Scan the matrix from the row 1~m-1 and the col 1~n-1 and set the entire col to zero if matrix[0][j]=0
		 for(int j=1; j<n; ++j){
			 if(matrix[0][j]==0){
				 for(int i=1; i<m; ++i)
				   matrix[i][j]=0;
			 }
		 }
		 // Set the first entire row to zero if firstRowZero is true
		 if (firstRowZero){
			 for(int j=0;j<n;++j)
			   matrix[0][j]=0;
		 }
		 // Set the first entire col to zero if firstColZero is true
		 if (firstColZero){
			 for(int i=0;i<m;++i)
			   matrix[i][0]=0;
		 }
	 }
 };

