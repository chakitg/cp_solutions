Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-

All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
 
There are two islands :- one is colored in "blue" and other in "red".
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'0', '1'}





class Solution {
  public:
   int n,m;
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
    void solve(vector<vector<char>>& grid,int i,int j){
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        for(auto &it:dir){
            int newi=i+it[0];
            int newj=j+it[1];
            solve(grid,newi,newj);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Aman Yadav
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
