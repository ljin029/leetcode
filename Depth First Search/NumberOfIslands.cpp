// Source : https://leetcode.com/problems/number-of-islands/
// Author : ljin029
// Date   : 2017-11-06

/********************************************************************************** 
 * 
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 * 
 * Example 1:
 *   11110
 *   11010
 *   11000
 *   00000
 * Answer: 1
 * 
 * Example 2:
 *   11000
 *   11000
 *   00100
 *   00011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 class Solution {
 public:
	 int numIslands(vector<vector<char>>& grid) {
		 if (grid.empty() || grid[0].empty()) return 0;
		 int row = grid.size();
		 int col = grid[0].size();
		 int res=0;
		 vector<vector<bool>> visited(row, vector<bool>(col, false));
		 
		 for(int i=0; i<row; ++i)
		 {
			 for(int j=0; j<col; ++j)
			 {
				 if (grid[i][j]=='1' && !visited[i][j])
				 {
					 numIslandsDFS(grid, visited, i, j);
					 ++res;
				 }
			 }
		 }
		 return res;
	 }
	 
	 void numIslandsDFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
	 {
		 if (i<0 || i>= grid.size()) return;
		 if (j<0 || j>= grid[0].size()) return;
		 if (grid[i][j]!='1' || visited[i][j]) return;
		 
		 visited[i][j]=true;
		 numIslandsDFS(grid, visited, i-1, j);
		 numIslandsDFS(grid, visited, i+1, j);
		 numIslandsDFS(grid, visited, i, j-1);
		 numIslandsDFS(grid, visited, i, j+1);
	 }
 };


