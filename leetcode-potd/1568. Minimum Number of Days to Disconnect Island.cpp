You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.






  class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note : Grid is said to be connected if there is excatly one island in it.
        // In one day we are allowd to change one land cell into water cell.
        // We need to return the minimum number of days to disconnect the grid.
        // Step - 1 : Count the number of islands that are present in the grid.
        vector<vector<int>> tmpGridStart(grid);
        // The grid is disconnected either if number of islands are 0 or number of islands are greater than or equal to 2.
        int rows = grid.size();
        int cols = grid[0].size();
        if(countNumberOfIslands(grid) != 1) return 0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                grid[i][j] = tmpGridStart[i][j];
            }
        }
        // The other finding of the problem
        // Given any shape of grid and the grid is having ones and zeros then the max number of islands that needs to be changed to make grid disconnected according to the given condition is 2
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 0) continue;
                vector<vector<int>> tmpGrid(grid);
                grid[i][j] = 0;
                int ans = countNumberOfIslands(grid);
                if(ans != 1) return 1;
                for(int a = 0 ; a < rows ; a++){
                    for(int b = 0 ; b < cols ; b++){
                        grid[a][b] = tmpGrid[a][b];
                    }
                }
            }
        }
        return 2;
    }
    int countNumberOfIslands(vector<vector<int>> &grid){
        // Variable to store the number of islands
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 1){
                    islands += 1;
                    changeGrid(grid, i, j);
                }
            }
        }
        return islands;
    }
    void changeGrid(vector<vector<int>> &grid, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        grid[row][col] = 0;
        vector<int> dr[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        q.push({row, col});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto &ele : dr){
                int tmpR = ele[0] + front.first;
                int tmpC = ele[1] + front.second;
                if(tmpR >= 0 and tmpR < rows and tmpC >= 0 and tmpC < cols and grid[tmpR][tmpC] == 1){
                    grid[tmpR][tmpC] = 0;
                    q.push({tmpR, tmpC});
                }
            }
        }

    }
};
