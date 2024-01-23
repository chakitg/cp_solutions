You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.





class Solution {
    int dfs(int idx, vector<string>& arr, vector<int> vis){
        if(idx == arr.size()) return 0;
        int skip = dfs(idx+1, arr, vis); 
        for(char c : arr[idx]){
            if(vis[c - 'a']) return skip;
            vis[c - 'a'] = 1;
        }
        int noskip = arr[idx].length() + dfs(idx+1, arr, vis);
        return max(skip, noskip);
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> vis(26, 0);
        return dfs(0, arr, vis);
    }
};
