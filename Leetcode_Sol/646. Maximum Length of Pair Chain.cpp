You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000



#define pii pair<int, int>
class Solution {
public:
    int n, dp[1005];
    pii a[1005];

    int solve(int i) {
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j=i+1; j<=n; j++){
            if(a[j].first > a[i].second){
                ans = max(ans, solve(j));
            }
        }
        return dp[i] = 1 + ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        n = pairs.size();
        for(int i=1; i<=n; i++) {
            a[i].first = pairs[i-1][0];
            a[i].second = pairs[i-1][1];
        }
        sort(a+1, a+1+n);
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, solve(i));
        }
        return ans;
    }
};


_____________________________________________________


class Solution {
public:
    int n;

    int solve(int i, vector<vector<int>> &a , vector<int>&dp) {
        if(i == n) {
            return 0;
        }

        if(dp[i] != -1) return dp[i];


        int ans = 0;

        vector<int>b = {a[i][1]+1,INT_MIN};
        int p = lower_bound(a.begin(),a.end(),b) - a.begin();
        ans = max(ans, 1 + solve(p,a,dp));
        ans = max(ans, solve(i+1,a,dp));
        return dp[i] = ans;
    }

    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        n = (int)a.size();
        vector<int>dp(n+2,-1);
        return solve(0,a,dp);
    }
};
