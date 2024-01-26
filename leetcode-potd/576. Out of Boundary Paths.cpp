There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n






class Solution {
public:
    int mod=1e9+7;  
    int solve(int i,int j,int m,int n,int mx,int dp[51][51][51])
    {
        if(mx==0) 
        {
           if(i>=m || i<0 || j>=n || j<0) return 1;
           return 0; 
        }
        
        if(i>=m || i<0 || j>=n || j<0) return 1;
        
        if(dp[i][j][mx]!=-1) return dp[i][j][mx];

        long long opt1=solve(i,j+1,m,n,mx-1,dp);
        long long opt2=solve(i+1,j,m,n,mx-1,dp);
        long long opt3=solve(i-1,j,m,n,mx-1,dp);
        long long opt4=solve(i,j-1,m,n,mx-1,dp);

        return dp[i][j][mx]=(opt1+opt2+opt3+opt4)%(mod);
    }
    int findPaths(int m, int n, int mx, int st, int sc) {
        int dp[51][51][51];

        memset(dp,-1,sizeof(dp));
        return solve(st,sc,m,n,mx,dp);
    }
};
