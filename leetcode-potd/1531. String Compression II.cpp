Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
 

Constraints:

1 <= s.length <= 100
0 <= k <= s.length
s contains only lowercase English letters.









class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length(); // Length of the input string
        vector<vector<int>> dp(101, vector<int>(101, 999)); // Dynamic programming array for memoization

        dp[0][0] = 0; // Base case: 0 deletions for an empty string results in 0 compression length

        // Loop through each character of the string
        for (int i = 1; i <= n; i++) {
            // Loop through possible deletion counts (0 to k)
            for (int j = 0; j <= k; j++) {
                int count = 0, del = 0; // Variables to store the count of consecutive characters and deletions

                // Loop backward from the current character to the beginning of the string
                for (int t = i; t >= 1; t--) {
                    if (s[t - 1] == s[i - 1])
                        count++; // Increment count if the characters are the same
                    else
                        del++; // Increment deletion count if the characters are different

                    // Check if the remaining deletions are sufficient for the current substring
                    if (j - del >= 0) {
                        int temp = 0;

                        // Determine the compression factor based on the count of consecutive characters
                        if (count >= 100)
                            temp = 3;
                        else if (count >= 10)
                            temp = 2;
                        else if (count >= 2)
                            temp = 1;

                        // Update the dp array with the minimum compression length
                        dp[i][j] = min(dp[i][j], dp[t - 1][j - del] + 1 + temp);
                    }
                }

                // Consider the case where a deletion is made at the current position
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        // Return the minimum compression length for the entire string with at most k deletions
        return dp[n][k];
    }
};
