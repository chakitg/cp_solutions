An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.





class Solution {
public:
    int dr[4]={0,0,1,-1},dc[4]={1,-1,0,0};
    void dfs(int r,int c,int n,vector<vector<int>> &mat){
        mat[r][c]=1;
        for(int k=0;k<4;k++){
            int nr = r + dr[k],nc = c + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<n && mat[nr][nc]==0)
                dfs(nr,nc,n,mat);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int r = i*3,c=j*3;
                if(grid[i][j]!=' ' && grid[i][j]=='\\'){
                    mat[r][c]=1;
                    mat[r+1][c+1]=1;
                    mat[r+2][c+2]=1;
                }
                else if(grid[i][j]!=' ' && grid[i][j]=='/'){
                    mat[r][c+2]=1;
                    mat[r+1][c+1]=1;
                    mat[r+2][c]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(mat[i][j]==0){
                    dfs(i,j,(n*3),mat);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
