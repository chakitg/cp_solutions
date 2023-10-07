Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.



class Solution {
public:
     bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if (n1+n2!=n3) return 0;
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1, -1));
        function<int(int, int)> dfs=[&](int i, int j)->int
        {
            if (i==n1 && j==n2) return dp[i][j]=1;
            if (dp[i][j]!=-1) return dp[i][j];
            int ch_s1, ch_s2;
            if (i<n1 && s1[i]==s3[i+j]) ch_s1=dfs(i+1,j);
            if (j<n2 && s2[j]==s3[i+j]) ch_s2=dfs(i,j+1);
            return dp[i][j]=ch_s1||ch_s2;
        };
        return dfs(0, 0)!=0;
    }
};
