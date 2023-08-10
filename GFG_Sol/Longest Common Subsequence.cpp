Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103



class Solution
{
   public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        //return solve(n , m , s1 , s2 , n-1 , m-1, dp);
        dp[0][0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        
        }
        return dp[n][m];
    }
    int solve(int n, int m, string &s1 , string &s2, int i , int j
    
        , vector<vector<int>> &dp){
        if(i==-1 || j==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //memo
        if(s1[i] == s2[j]){
            return dp[i][j] = 1+solve(n, m , s1 , s2 ,i-1 , j-1, dp);
        }
        else{
            return dp[i][j] = max(solve(n , m , s1 , s2 , i-1 , j ,dp) , 
                        solve(n , m , s1 , s2 , i , j-1 , dp));
        }
    }
};
