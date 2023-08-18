You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000


class Solution {
public:
    int solve(int i , int buy , int cap , vector<int> & prices , int n,vector<vector<vector<int>>> &dp) {
        if(i == n || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy == 1) {
            return dp[i][buy][cap] = max(-prices[i] + solve(i+1,0,cap,prices,n,dp) , solve(i+1,1,cap,prices,n,dp));
        }
        return dp[i][buy][cap] = max(prices[i] + solve(i+1,1,cap-1,prices,n,dp), solve(i+1,0,cap,prices,n,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
      int n = (int)prices.size();
      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
      return solve(0,1,k,prices,n,dp);
    }
};
