Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.





  class Solution {
public:
    int n;
    vector<vector<bool>> dp;

    //judge whether s[l..r] is palindrome
    inline bool isPalindrome(string& s, int l, int r){
        while (l < r){
            if (s[l] != s[r]) return  0;     
            l++;
            r--;       
        }
        return 1;
    }
    // Compute dp[l][r] for every substring s[l..r]
    inline void compute_DP(string& s){
        for(int l=0; l<n; l++)
            for(int r=l; r<n; r++)
                dp[l][r]=isPalindrome(s, l, r);
    }

    // backtracking to find the valid partitions for s[start:]
    vector<vector<string>> ans;
    inline void dfs(string &s, int start, vector<string>& valids) {
        if (start >= n)
            ans.push_back(valids);
        for (int end = start; end < n; end++) {
            if (dp[start][end]) {
                valids.push_back(s.substr(start, end - start + 1));
                dfs(s, end+1, valids);
                valids.pop_back();//backtracking
            }
        }
    }

    vector<vector<string>> partition(string& s) {
        n = s.size();
        if (n == 1) return {{s}};
        dp.assign(n, vector<bool>(n, 0));
        compute_DP(s);
        vector<string> valids;
        dfs(s, 0, valids);
        return ans;
    }
};
