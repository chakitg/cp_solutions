As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

His 2024 resolution: Solve POTD every day.

Eager to earn coins for GFG Merchandise, Geek faces new rules:

Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?

Example 1:

Input:
N = 8
coins = [5, 8, 9, 10, 14, 2, 3, 5]

Output: 1

Explanation:
Geek can fulfill the criteria in many ways.
One such way is to solve POTD on 4th and 5th day.
Another way is to solve POTD on 1st, 4th and 8th day.
Example 2:

Input:
N = 5
coins = [1, 2, 3, 4, 5]

Output: 0

Explanation: There is no way Geek can become eligible.
Your Task: 
You don't need to read input or print anything. Complete the function isPossible() which takes n and coins[ ] as input parameters and returns a boolean value.

Expected Time Complexity: O(N*(Sum of coins))
Expected Auxiliary Space: O(N*(Sum of coins))

Constraints:
1 <= N <= 366
1 <= coins[i] <= 2024
1 <= Sum of coins <=  2024





class Solution {
public:
    bool solve(int i, int& n, int sum, int coins[], vector<unordered_map<int,bool>>& dp){
        if(sum == 2024 || (sum && (sum%20 == 0 || sum%24 == 0)))
            return true;
        
        if(i == n || sum > 2024)
            return false;
        
        if(dp[i].find(sum) != dp[i].end())
            return dp[i][sum];
        
        int nt = solve(i+1, n, sum, coins, dp);
        if(nt)
            return dp[i][sum] = nt;
        
        return dp[i][sum] = solve(i+1, n, sum + coins[i], coins, dp);
    }
    
    int isPossible(int n , int coins[]) 
    {
        vector<unordered_map<int,bool>> dp(n);
        return solve(0,n,0,coins, dp);
    }
};
