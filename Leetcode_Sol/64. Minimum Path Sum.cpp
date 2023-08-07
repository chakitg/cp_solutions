Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int dp[n][m];
        int inf = 1e4;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                dp[i][j] = inf;
            }
        }
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < n ; i++) {
         for(int j = 0 ; j < m ; j++) {
             if(i+1 < n && j < m)  {
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + grid[i+1][j]);
             }
             if(i < n && j+1 < m) {
                 dp[i][j+1] = min(dp[i][j+1],dp[i][j] + grid[i][j+1]);
             }
         }
        }
        return dp[n-1][m-1];
    }
};
