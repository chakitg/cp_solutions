A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000




class Solution {
public:
    int solve(int i , int k , vector<int>&a , vector<vector<int>>&dp) {
        if(i >= (int)a.size()) return 0;
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        int ans = 0;
        ans = max(solve(i+1,k,a,dp), a[i]*k + solve(i+1,k+1,a,dp));
        return dp[i][k] = ans;
    }

    int maxSatisfaction(vector<int>& a) {
     sort(a.begin(),a.end());
     int n = (int)a.size();
     vector<vector<int>>dp(n+4,vector<int>(n+4,-1));   
     return solve(0,1,a,dp);
    }
};
