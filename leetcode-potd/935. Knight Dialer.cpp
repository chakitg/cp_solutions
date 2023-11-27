The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
 

Constraints:

1 <= n <= 5000




class Solution {
    int MOD=1000000007;
    int solve(int n,int i,int count,vector<vector<int>>& map,vector<vector<int>>& dp){
        if(count==n)return 1;
        if(dp[i][count]!=-1)return dp[i][count];

        int sum=0;
        for(auto index:map[i]){
            int temp=solve(n,index,count+1,map,dp)%MOD;
            sum=((sum)%MOD+temp)%MOD;
        }
        return dp[i][count]=sum%MOD;
    }
public:
    int knightDialer(int n) {
        vector<vector<int>>map={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        int ans=0;
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        for(int i=0;i<10;i++){
            int temp=solve(n,i,1,map,dp);
            ans=((ans)%MOD+temp)%MOD;
        }
        return ans;
    }
};
