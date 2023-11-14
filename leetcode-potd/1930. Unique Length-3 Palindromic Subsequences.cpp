Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.



class Solution {
public:
    // time/space: O(n)/O(n)
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // record the characters on the left/right (starting from the index `1`)
        unordered_map<char, int> left, right;
        left[s[0]]++;
        for (int i = 2; i < n; i++) right[s[i]]++;

        int result = 0;
        unordered_set<string> visited;
        for (int i = 1; i < (n - 1); i++) {
            // generate length-3 palindromes
            for (char c = 'a'; c <= 'z'; c++) {
                if (left.count(c) == 0) continue;
                if (right.count(c) == 0) continue;
                const string palindrome = {c, s[i], c};
                if (visited.count(palindrome) != 0) continue;
                visited.insert(palindrome);
                result++;
            }
            // update `left` and `right`
            left[s[i]]++;
            if ((--right[s[i + 1]]) == 0) right.erase(s[i + 1]);
        }
        return result;
    }
};
