Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.



class Solution {
public:
    int partitionString(string s) {
        int n = (int)s.size();
        set<char>x;
        int ans = 1;
        for(int i = 0 ; i < n ; i++) {
            if(x.find(s[i]) != x.end()) {
                x.clear();
                ++ans;
            }
            x.insert(s[i]);
        }
        return ans;
    }
};
