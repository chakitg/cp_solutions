Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.



class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            result += word + ' ';
        }
        result.pop_back(); // Remove the trailing space
        return result;
    }
};
