Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:

Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
Example 2:

 

Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500



class Solution{
public:
    void bfs(vector<vector<char>> &mat, vector<vector<int>> &vis, int i, int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        while(!q.empty()) {
            auto qFront = q.front();
            q.pop();
            int x = qFront.first;
            int y = qFront.second;
            
            vis[x][y] = 1;
            
            // check the four neighbour for 'O' and push to queue
            for(int i=0; i<4; i++) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                
                // check for valid coordinate
                if(nx>=0 && nx<n && ny>=0 && ny<m) {
                    // check for 'O' and not visited
                    if(mat[nx][ny]=='O' && !vis[nx][ny])
                        q.push({nx, ny});
                }
            }
        }
        
        
        
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        // traverse the boundary elements 
        // if it is 'O' then mark all connected as visited
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // check if the boundary is 'O'
                if((i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O') {
                    bfs(mat, vis, i, j, n, m);
                }
            }
        }
        
        // traversed the matrix again
        // mark all 'O' that are not visited
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};
