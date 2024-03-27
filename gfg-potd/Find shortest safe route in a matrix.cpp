Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.

Example 1:

Input:
mat = [1, 0, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 0, 1],
      [1, 1, 1, 1, 0]
Output: 
6
Explanation: 
We can see that length of shortest
safe route is 6
[1 0 1 1 1]
[1 1 1 1 1]
[1 1 1 1 1]
[1 1 1 0 1] 
[1 1 1 1 0]
Example 2:

Input:
mat = [1, 1, 1, 1, 1],
      [1, 1, 0, 1, 1],
      [1, 1, 1, 1, 1]
Output: 
-1
Explanation: There is no possible path from
first column to last column.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findShortestPath() which takes the matrix as an input parameter and returns an integer denoting the shortest safe path from any cell in the leftmost column to any cell in the rightmost column of mat. If there is no possible path, return -1. 

Expected Time Complexity: O(r * c)
Expected Auxiliary Space: O(r * c)

Constraints:
1 <= r, c <= 103
0 <= mat[][] <= 1





class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int findShortestPath(vector<vector<int>> &mat){
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        
        vector<pair<int, int>> bombs;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) 
                    bombs.push_back({i, j}); 
                    
        for(auto itr : bombs){
            for(int d = 0; d < 4; ++d){
                int x = itr.first + dx[d];
                int y = itr.second + dy[d];
                if(x >= 0 && y >= 0 && x < m && y < n)
                    mat[x][y] = 0;
            }
        }
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i) 
            if(mat[i][0]){ 
                mat[i][0] = 0;
                q.push({i, 0});
            }
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f.second == n-1) 
                    return ans;
                    
                for(int d = 0; d < 4; ++d){
                    int x = f.first + dx[d];
                    int y = f.second + dy[d];
                    if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y]){
                        mat[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    }
};
