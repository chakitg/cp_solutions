Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};



class Solution {
public:
    unordered_map<string,int>mp;
    int n;

    int solve(int i , string &s , vector<int> &dp) {
        if(i >= n) {
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        string t = "";
        for(int j = i ; j < n ; j++) {
            t += s[j];
            if(mp.find(t) != mp.end()) {
                ans |= solve(j+1,s,dp);
            }
        }
        return dp[i] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) mp[x]++;
        n = (int)s.size();
        vector<int>dp(n+2,-1);

        return solve(0,s,dp);
        
    }
};
