Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Example 2:

Input: 
s = "ggg"
Output: 
4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".
Your task:
You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets


class Solution {
public:
    int mod = 1e9 + 7;
    
    int distinctSubsequences(string s) {
        int n = s.size();
        
        vector<int> last(26, -1);
        long long dp[n + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2;
            int lastOccur = last[s[i - 1] - 'a'];
            
            if (lastOccur != -1) {
                dp[i] -= dp[lastOccur];
                if (dp[i] < 0)
                    dp[i] += mod;
            }
            dp[i] %= mod;
            last[s[i - 1] - 'a'] = i - 1;
        }
        return dp[n];
    }
};
