You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

Expected Time Complexity: O(n * m)

Expected Space Complexity: O(n * m)

Constraints:

1 <= n, m <= 500
grid[i][j] == 0 or 1




class Solution {
public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = -1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                dfs(grid, x, y, n, m);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }

        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cnt += (grid[i][j] == 1);
        }
        return cnt;
    }
};
