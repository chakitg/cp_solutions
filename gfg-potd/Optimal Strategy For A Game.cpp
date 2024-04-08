You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
n = 4
arr[] = {5, 3, 7, 10}
Output: 
15
Explanation: The user collects maximum
value as 15(10 + 5). It is guarantee that we cannot get more than 15 by any possible moves.
Example 2:

Input:
n = 4
arr[] = {8, 15, 3, 7}
Output: 
22
Explanation: The user collects maximum
value as 22(7 + 15). It is guarantee that we cannot get more than 22 by any possible moves.
Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of n coins) and n as a number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(n*n)
Expected Auxiliary Space: O(n*n)

Constraints:
2 <= n <= 103
1 <= arr[i] <= 106





class Solution{
    public:


    long long dp[1001][1001];

    long long solve(int n, int  arr[], int i, int j){

        // Base Case 
        if(i > j) return 0; // we are done with the game 

        // 
        if(dp[i][j] != -1) return dp[i][j];

        // 
        long long take = arr[i] + min(solve(n, arr, i + 2, j), solve(n, arr, i + 1, j - 1));
        long long not_take = arr[j] + min(solve(n, arr, i + 1, j - 1), solve(n, arr, i, j - 2));

        long long ans = max(take, not_take);

        return dp[i][j] = ans;

    }
    long long maximumAmount(int n, int arr[]){
        // Your code here

        memset(dp, -1, sizeof(dp));

        return solve(n, arr, 0, n -1);
    }
};
