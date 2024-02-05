Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.




class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> oc(26);
        //store frequency of each character of s
        for (auto i : s) oc[i - 'a']++;
        //first character with frequency = 1 is the answer
        for (int i = 0; i < s.size(); i++) {
            if (oc[s[i] - 'a'] == 1) return i;
        }
        //no character with frequency = 1
        return -1;
    }
};
