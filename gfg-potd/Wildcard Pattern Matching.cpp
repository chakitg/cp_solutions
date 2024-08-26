Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:

Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 <= length of(str, pattern) <= 200



class Solution {
  public:
    /*You are required to complete this method*/

    bool solve(string pattern , string str  , int i , int j , int n , int m , vector<vector<int>>& dp){

        if( i == n && j==m) return true;


        if(dp[i][j] != -1) return dp[i][j];

        if(j==m){
            while(i<pattern.length() && pattern[i]=='*') i++;
            return i == n;
        }
        bool ch1 = false; 
        bool ch2  = false;
        bool ch3= false;
        bool ch4 = false;
        bool ch5 = false;


        if(pattern[i] == '*') {
            ch1 =  solve(pattern,str , i , j+1 , n , m ,dp);
            ch4 = solve(pattern , str, i+1, j+1, n, m,dp);
            ch5 = solve(pattern , str ,i+1, j,n,m ,dp);            
        }
        if(pattern[i] == str[j]) ch2 =    solve(pattern , str, i+1, j+1, n , m ,dp);

        if(pattern[i] == '?') ch3= solve(pattern , str, i+1 , j+1 , n, m , dp);
        return dp[i][j] = ch1 || ch2 || ch3 || ch4 || ch5;
    }
    int wildCard(string pattern, string str) {

       // if(pattern.length() > str.length()) return false;

       vector<vector<int>>dp(pattern.length()+1,  vector<int>(str.length()+1,-1));
        return solve(pattern , str , 0 , 0 , pattern.length() , str.length(),dp);
    }
};
