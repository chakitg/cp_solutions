You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

Example 1:

Input:
x = 3, y = 0 
Output: 
1
Explanation: Path used was -  (3,0)  --> ( 2,0) --> (1,0) --> (0,0).We can see that there is no other path than this, so we return 1.
Example 2:

Input:
x = 3, y = 6
Output: 
84 
Explanation:
There are total 84 possible paths.
Your Task:
Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function ways() that takes integer x and y as parameters and returns the total number of paths from point(x,y) to the origin(0,0) % 1000000007.

Expected Time Complexity: O(x*y).
Expected Auxiliary Space: O(x*y).

Constraints:
0 ≤ x, y ≤ 500




class Solution
{
public:
    int mod=1e9+7;
    int solve(int x, int y, vector<vector<int>>&dp){
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];

        int left=0,up=0;
        if(y>0){
            left=solve(x,y-1,dp)%mod;
        }
        if(x>0){
            up=solve(x-1,y,dp)%mod;
        }

        return dp[x][y] = (left+up)%mod;
    }
    int ways(int x, int y)
    {
        //code here.
         vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return solve(x,y,dp);
    }
};
