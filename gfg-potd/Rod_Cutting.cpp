// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: Consider 1-based indexing.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.
// Example 2:

// Input:
// N=8
// Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
// Output: 
// 24
// Explanation: 
// The maximum obtainable value is 
// 24 by cutting the rod into 8 pieces 
// of length 1, i.e, 8*3=24. 
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 1000
// 1 ≤ Ai ≤ 105






class Solution{
  public:
    int fun(int i,int n,int price[],vector<vector<int>>&dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1)    return dp[i][n];
        int nt = 0 + fun(i-1,n,price,dp);
        int tk = -1e9;
        if(i+1<=n)
        tk = price[i] + fun(i,n-i-1,price,dp);
        return dp[i][n] = max(tk,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(n-1,n,price,dp);
    }
};
