You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

 

Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
 

Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.





class Solution {
public:
    // Function to check the count of consecutive characters within a range
    int checkCnt(int idx, int k, vector<int>& cnts){
        int ans = 0, cnt=0;
        int currIdx = idx;
        // Count consecutive characters to the left
        while(currIdx >= 0 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx--;
            cnt++;
        }
        currIdx = idx;
        cnt = 0;
        // Count consecutive characters to the right
        while(currIdx<26 && cnt<=k){
            ans = max(ans, cnts[currIdx]);
            currIdx++;
            cnt++;
        }
        return ans;
    }

    // Function to find the length of the longest "ideal" string
    int longestIdealString(string s, int k) {
        // Array to store the count of characters
        vector<int> cnts(26, 0);
        int ans = 0;
        // Iterate through the string
        for(int i=0; i<s.size(); i++){
            int idx = s[i]-'a';
            // Update count of current character based on surrounding characters
            cnts[idx] = checkCnt(idx, k, cnts)+1;
        }
        // Find the maximum count in the count array
        for(int i=0; i<cnts.size(); i++){
            ans = max(ans, cnts[i]);
        }
        return ans;
    }
};
