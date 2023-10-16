You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. A group of connected 1s forms an island. Two 1s are connected if they share one of their sides with each other.

Return the size of the largest island in the grid after applying this operation.

Example 1:

Input: 
grid = [[1,0],[0,1]]
Output:
3
Explanation:
Change any one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: 
grid = [[1,1],[1,0]]
Output:
4
Explanation:
Change the only 0 to 1 and make the island bigger, then we get an island with area = 4.
Example 3:

Input: 
grid = [[1,1],[1,1]]
Output:
4
Explanation:
Can't change any 0 to 1, only one island possible with area = 4.
Your Task:

You don't have to read input or print anything. You have to complete the functions largestIsland(), which takes binary matrix as input and returns an integer denoting the size of the largest island in grid after applying the operation.

Constraints:

1 <= n <= 500
0 <= grid[i][j] <= 1 (grid[i][j] ∈ {0, 1} and 0<=i,j<n)


class Solution {
public:
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int& id, int& n) {
        grid[i][j] = id;
        int c = 1;
        for (int d = 0; d < 4; ++d) {
            int x = dx[d] + i;
            int y = dy[d] + j;
            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1)
                c += dfs(grid, x, y, id, n);
        }
        return c;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int out = 0;
        unordered_map<int, int> mp;
        int id = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++id;
                    int c = dfs(grid, i , j, id, n);
                    mp[id] = c;
                    out = max(out, c);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int c = 1;
                    set<int> st;
                    for (int d = 0; d < 4; ++d) {
                        int x = dx[d] + i;
                        int y = dy[d] + j;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1)
                            st.insert(grid[x][y]);
                    }
                    for (auto i : st)
                        c += mp[i];
                    out = max(out, c);
                }
            }
        }
        return out;
    }
};
