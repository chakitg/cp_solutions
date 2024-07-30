Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1





class Solution {
  public:
    vector<string> ans;
    void find(vector<vector<int>> &mat, int i, int j, int n, vector<vector<bool>> vis, string st){
        if(vis[i][j] || mat[i][j]==0)
            return;
        if(i==n-1 && j==n-1){
            ans.push_back(st);
            return;
        }
        vis[i][j] = true;
        if(i<n-1){
            find(mat, i+1, j, n, vis, st+"D");
        }
        if(j<n-1){
            find(mat, i, j+1, n, vis, st+"R");
        }
        if(i>0){
            find(mat, i-1, j, n, vis, st+"U");
        }
        if(j>0){
            find(mat, i, j-1, n, vis, st+"L");
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0)
            return {"-1"};
        int n = mat.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        find(mat, 0, 0, n, vis, "");
        return ans;
    }
};
