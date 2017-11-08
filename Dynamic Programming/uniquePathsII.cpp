// Source : https://oj.leetcode.com/problems/unique-paths-ii/
// Author : ljin029
// Date   : 2017-11-08

/********************************************************************************** 
* 
* Follow up for "Unique Paths":
* 
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
* 
* An obstacle and empty space is marked as 1 and 0 respectively in the grid.
* 
* For example,
* There is one obstacle in the middle of a 3x3 grid as illustrated below.
* 
* [
*   [0,0,0],
*   [0,1,0],
*   [0,0,0]
* ]
* 
* The total number of unique paths is 2.
* 
* Note: m and n will be at most 100.
*               
**********************************************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0)); // initialized to 0

		// initialize the first col
        for(int i=0; i<m; ++i)
        {
            if(obstacleGrid[i][0]==1) break;
            dp[i][0]=1;
        }
		// initialize the first row
        for(int i=0; i<n; ++i)
        {
            if(obstacleGrid[0][i]==1) break;
            dp[0][i]=1;
        }
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};


