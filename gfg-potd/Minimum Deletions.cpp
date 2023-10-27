Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: 
S = "aebcbda"
Output: 
2
Explanation: 
Remove characters 'e' and 'd'.
Example 2:

Input: 
S = "geeksforgeeks"
Output: 
8
Explanation: 
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103




class Solution {
public:
    int lcs(string &S, string &revS, int i, int j, vector<vector<int> > &dp) {
        if (i == -1 || j == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (S[i] == revS[j])
            return dp[i][j] = 1 + lcs(S, revS, i - 1, j - 1, dp);

        int checkS = lcs(S, revS, i - 1, j, dp);
        int checkRevS = lcs(S, revS, i, j - 1, dp);
        return dp[i][j] = max(checkS, checkRevS);
    }

    int minimumNumberOfDeletions(string S) {
        int n = S.size();
        string revS = S;
        reverse(revS.begin(), revS.end());
        vector<vector<int> > dp(n, vector<int>(n, -1));

        return n - lcs(S, revS, n - 1, n - 1, dp);
    }
};
