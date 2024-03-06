Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

Example 1:

Input: 
text = "birthdayboy"
pattern = "birth"
Output: 
[1]
Explanation: 
The string "birth" occurs at index 1 in text.
Example 2:

Input:
text = "geeksforgeeks"
pattern = "geek"
Output: 
[1, 9]
Explanation: 
The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string text and the string pattern as input and returns an array denoting the start indices (1-based) of substring pattern in the string text. 

Expected Time Complexity: O(|text| + |pattern|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|text|<=5*105
1<=|pattern|<=|text|




class Solution {
public:
    vector<int> search(string pattern, string text) {
        vector<int> out;
        int mod = 10;
        int h = pattern.size();
        int n = text.size();
        int hashp = 0;
        int hasht = 0;
        int p = 1;
        
        for (int i = 0; i < h - 1; ++i)
            p = (p * 26) % mod;
        
        for (int i = 0; i < h; ++i) {
            hashp = ((hashp * 26) + pattern[i]) % mod;
            hasht = ((hasht * 26) + text[i]) % mod;
        }
        
        for (int i = 0; i <= n - h; ++i) {
            if (hashp == hasht) {
                int j;
                for (j = 0; j < h; ++j)
                    if (pattern[j] != text[i + j])
                        break;
                        
                if (j == h)
                    out.push_back(i + 1);
            }
            if (i < n - h) {
                hasht = (26 * (hasht - text[i] * p) + text[i + h]) % mod;
                if (hasht < 0)
                    hasht += mod;
            }
        }
        return out;
    }
};
