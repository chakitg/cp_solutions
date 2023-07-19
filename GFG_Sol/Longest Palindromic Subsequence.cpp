Given a String, find the longest palindromic subsequence.

Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).

Constraints:
1 ≤ |S| ≤ 1000



class Solution{
  public:
    int lcs(string a, string b, int n) 
    { 
        vector<vector<int>> v(n + 1, vector<int> (n + 1, 0)); 
        for(int i = 1; i <= n; i++) 
        { 
            for(int j = 1; j <= n; j++) 
            { 
                if(a[i - 1] == b[j - 1]) 
                { 
                    v[i][j] = 1 + v[i - 1][j - 1]; 
                } 
                else 
                { 
                    v[i][j] = max(v[i - 1][j], v[i][j - 1]); 
                } 
            } 
        } 
        return v[n][n]; 
    } 
    int longestPalinSubseq(string A) { 
        //code herere 
        string s = A; 
        int n = s.size(); 
        reverse(s.begin(), s.end()); 
        int x = lcs(A, s, n); 
        return x; 
    }
};
