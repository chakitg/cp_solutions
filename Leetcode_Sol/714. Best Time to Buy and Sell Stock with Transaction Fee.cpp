714. Best Time to Buy and Sell Stock with Transaction Fee
Medium

6620

183

Add to List

Share
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104


class Solution {
public:

    int solve(int i , int buy, vector<int>&prices, int fee, int n, vector<vector<int>>&dp) {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy) {
         profit = max(-prices[i] - fee + solve(i+1,0,prices,fee,n,dp) , solve(i+1,1,prices,fee,n,dp));
        }
        else {
         profit = max(prices[i] + solve(i+1,1,prices,fee,n,dp) , solve(i+1,0,prices,fee,n,dp));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,n,dp);
    }
};
