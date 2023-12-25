A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).





class Solution {
public:
    int numDecodingsRec(string s, int i)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        int count = 0;
        // Including 1 char
        count += numDecodingsRec(s, i + 1);
        // Including 2 chars
        if(i + 1 < s.size() and s.substr(i,2) < "27")
            count += numDecodingsRec(s, i + 2);
        
        return count;
    }

    // Top-Down Approach : Memoization
    int numDecodingsMem(string s, int i, vector<int>& dp)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int count = 0;
        // Including 1 char
        count += numDecodingsMem(s, i + 1, dp);
        // Including 2 chars
        if(i + 1 < s.size() and s.substr(i,2) < "27")
            count += numDecodingsMem(s, i + 2, dp);
        
        return dp[i] = count;
    }

    int numDecodings(string s) {
        // 1. Recursion
        // return numDecodingsRec(s,0);
        // 2. Memoization
        vector<int> dp(s.size()+1, -1);
        return numDecodingsMem(s,0,dp);
    }
};
