For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 

Constraints:

1 <= n <= 1000
0 <= k <= 1000




class Solution {
    int dp[1001][1001], mod = 1e9 + 7;
    long long dfs(int n, int k){
        if(n == 0) return 0;
        if(k == 0) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        long long last = min(k, n-1), ans = 0;
        // f(n,k)=f(n−1,k)+f(n−1,k−1)+f(n−1,k−2)+⋯+f(n−1,k−n+1)
        for(int i = 0;i <= last;i++)
            ans = (ans + dfs(n-1, k-i))%mod;
        return dp[n][k] = ans%mod;
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(n, k) % mod;
    }
};
