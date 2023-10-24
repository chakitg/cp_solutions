Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500




class Solution {
public:
    bool isPalin(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    
    int check(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (isPalin(i, j, s)) return dp[i][j] = 0;
        
        int out = INT_MAX;
        for (int k = i; k < j; ++k) {
            if (isPalin(i, k, s)) {
                out = min(out, 1 + check(k + 1, j, s, dp));
            }
        }
        return dp[i][j] = out;
    }
    
    int palindromicPartition(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        check(0, n - 1, str, dp);
        return check(0, n - 1, str, dp);
    }
};
