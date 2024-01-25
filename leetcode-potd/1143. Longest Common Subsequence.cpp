Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.



class Solution {
public:
    int dp[1007][1007];
    
    int solve(int i , int j , string &s , string &t) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = solve(i-1,j,s,t);
        res = max(res,solve(i,j-1,s,t));
        res = max(res,solve(i-1,j-1,s,t) + (s[i] == t[j]));
        return dp[i][j] = res;
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = (int)text1.size();
        int m = (int)text2.size();
        return solve(n-1,m-1,text1,text2);
    }
};



--------------------------------------------

 class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() < text2.length()) {
            return LCS(text1, text2);
        }
        return LCS(text2, text1);
    }

    int LCS(string s1, string s2) {
        vector<vector<int>> M(2, vector<int>(s1.length() + 1, 0));

        for (int i = 1; i <= s2.length(); i++) {
            M[i % 2][0] = 0;
            for (int j = 1; j <= s1.length(); j++) {
                if (s1[j - 1] == s2[i - 1]) {
                    M[i % 2][j] = M[(i - 1) % 2][j - 1] + 1;
                } else {
                    M[i % 2][j] = max(M[(i - 1) % 2][j - 1],
                                max(M[(i - 1) % 2][j], M[i % 2][j - 1]));
                }
            }
        }
        return M[s2.length() % 2][s1.length()];
    }
};
