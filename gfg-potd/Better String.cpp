Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences. 
Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.

Expected Time Complexity: O( max( str1.length, str2.length ) )

Expected Auxiliary Space: O( max( str1.length, str2.length ) )

Constraints:
1 <= str1.length , str2.length <= 30




class Solution {
public:
    int distSubSeq(string s)
    {
        unordered_map<char, int> last;
        int count = 1;

        for (auto ch : s) {
            int newCount = 2 * count;

            if (last.find(ch) != last.end())
                newCount -= last[ch];

            last[ch] = count;
            count = newCount;
        }
        return count;
    }

    string betterString(string s1, string s2) {
        int distSubSeq1 = distSubSeq(s1);
        int distSubSeq2 = distSubSeq(s2);

        return distSubSeq2 > distSubSeq1 ? s2 : s1;
    }
};
