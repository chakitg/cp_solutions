Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.







  class Solution {
public:
    int solve(int i , int j,string &s , string &t, vector<vector<int>>& dp) {
     if(i < 0) return j+1;
     if(j < 0) return i+1;
     if(dp[i][j] != -1) return dp[i][j];
     if(s[i] == t[j]) {
        return dp[i][j] = solve(i-1,j-1,s,t,dp);
     }
     else {
        return dp[i][j] = 1 + min({solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp),solve(i-1,j-1,s,t,dp)});
     }
    }

    int minDistance(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};
