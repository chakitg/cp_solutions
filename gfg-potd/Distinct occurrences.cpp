Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

Example 1:

Input:
s = "banana" , t = "ban"
Output: 
3
Explanation: 
There are 3 sub-sequences:[ban], [ba n], [b an].
Example 2:

Input:
s = "geeksforgeeks" , t = "ge"
Output: 
6
Explanation: 
There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument s and t and returns the count of the sub-sequences modulo 109 + 7.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1 ≤ n,m ≤ 1000






class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int j, int n, int m, string s, string t, vector<vector<int>>& dp) {
        if (j == m)
            return 1;
        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ntake = solve(i + 1, j, n, m, s, t, dp);
        int take = 0;
        if (s[i] == t[j])
            take = solve(i + 1, j + 1, n, m, s, t, dp);

        return dp[i][j] = (take + ntake) % mod;
    }

    int subsequenceCount(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, n, m, s, t, dp);
    }
};
