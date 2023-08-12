You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100


class Solution {
public:
    int N;

    int solve(int i , int ones , int zeros, vector<pair<int,int>>&a , vector<vector<vector<int>>> &dp) {
        if(i == N) {
            if(ones >= 0 && zeros >= 0) {
                return 0;
            }
            return -1e6;
        }
        if(dp[i][ones][zeros] != -1) return dp[i][ones][zeros];
        int ans = -1e6;
        if(zeros-a[i].first >= 0 && ones-a[i].second >= 0) {
            ans = max(ans, 1 + solve(i+1,ones-a[i].second,zeros-a[i].first,a,dp));
        }
        ans = max(ans,solve(i+1,ones,zeros,a,dp));
        return dp[i][ones][zeros] = ans;
    } 

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>a;
        for(auto x : strs) {
            int z = 0;
            int o = 0;
            for(auto t : x) {
                if(t == '0') ++z;
                else ++o;
            }
            a.push_back({z,o});
        }
        N = (int)strs.size();

        vector<vector<vector<int>>>dp(N+2,vector<vector<int>>(n+4,vector<int>(m+4,-1)));
        return solve(0,n,m,a,dp);
    }
};
