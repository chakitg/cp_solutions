Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.



class Solution {
public:
    int dp[505][505];
    int solve(int l , int r, string &s) {
        if(l >= r) {
          return 0;
        }
        if(dp[l][r] != -1) {
         return dp[l][r];
        }
        int ans = 1e8;
        if(s[l] == s[r]) {
         ans = min(ans,solve(l+1,r-1,s));
        }
        ans = min(ans,1 + solve(l+1,r,s));
        ans = min(ans,1 + solve(l,r-1,s));
        return dp[l][r] = ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,(int)s.size()-1,s);
    }
};
