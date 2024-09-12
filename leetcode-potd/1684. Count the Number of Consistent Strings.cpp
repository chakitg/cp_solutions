You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.







class Solution {
private:
    bool helper(string word, unordered_set<char> &us){
        bool ans = true;
        for(auto &ch : word){
            ans = ans && (us.find(ch) != us.end());
        }
        return ans;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // String allowed consists of distinct characters.
        // Given an array of words
        // we can a string consisitent if all the characters appear in the string allowed
        // We need to find out how many words of given vector are consistent.
        // allowed = ab
        // ad, bd, [aaab], [baa], dadab
        int ans = 0;
        unordered_set<char> us;
        for(auto &ch : allowed) us.insert(ch);
        for(auto &word : words) {
            ans += helper(word, us);
        }
        return ans;
    }
};
