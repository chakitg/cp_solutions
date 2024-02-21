Given a boolean expression s of length n with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003

Example 1:

Input: 
n = 7
s = T|T&F^T
Output: 
4
Explaination: 
The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: 
n = 5
s = T^F|F
Output: 
2
Explaination: 
((T^F)|F) and (T^(F|F)) are the only ways.
Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes n and s as input parameters and returns number of possible ways modulo 1003.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ n ≤ 200 




class Solution{
public:
    int countWays(int n, string s){
        int dp[n][n][2];
        const int mod = 1003;
        
        for(int i = n - 1; i > -1; i -= 2){
            for(int j = i; j < n; j += 2){
                if(i == j){
                    dp[i][j][1] = s[i] == 'T';
                    dp[i][j][0] = s[i] == 'F';
                }
                else{
                    dp[i][j][1] = dp[i][j][0] = 0;
                    
                    for(int k = i; k < j; k += 2){
                        int f1 = dp[i][k][1], f0 = dp[i][k][0], s1 = dp[k + 2][j][1], s0 = dp[k + 2][j][0];
                        
                        if(s[k + 1] == '&'){
                            dp[i][j][1] = (dp[i][j][1] + (f1 * s1) % mod) % mod;
                            dp[i][j][0] = (dp[i][j][0] + (f1 * s0) % mod + (f0 * s1) % mod + (f0 * s0) % mod) % mod; 
                        }
                        else if(s[k + 1] == '|'){
                            dp[i][j][1] = (dp[i][j][1] + (f1 * s0) % mod + (f0 * s1) % mod + (f1 * s1) % mod) % mod; 
                            dp[i][j][0] = (dp[i][j][0] + (f0 * s0) % mod) % mod;
                        }
                        else{
                            dp[i][j][1] = (dp[i][j][1] + (f1 * s0) % mod + (f0 * s1) % mod) % mod;
                            dp[i][j][0] = (dp[i][j][0] + (f1 * s1) % mod + (f0 * s0) % mod) % mod;
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1][1];
    }
};
