Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.
Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1 ≤ |S| ≤ 105
1 ≤ K ≤ 26
All characters are lowercase latin characters.



class Solution{
  public:
    int longestKSubstr(string s, int k) {
    if (k > s.size()) {
        return -1;
    }

    unordered_map<char, int> charCount; // To keep track of the count of each character in the current window
    int max_length = 0; // To store the length of the longest substring
    int start = 0; // The start index of the current window
    string longestSubstring = ""; // To store the longest substring

    for (int end = 0; end < s.length(); end++) {
        // Add the current character to the window
        char ch = s[end];
        charCount[ch]++;

        // If the number of unique characters exceeds K, shrink the window from the left
        while (charCount.size() > k) {
            char leftChar = s[start];
            charCount[leftChar]--;
            if (charCount[leftChar] == 0) {
                charCount.erase(leftChar);
            }
            start++;
        }

        // Update the maximum length and longest substring if needed
        if (end - start + 1 > max_length) {
            max_length = end - start + 1;
            longestSubstring = s.substr(start, max_length);
        }
    }

    return longestSubstring.size();

    }
    
    
};
