Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.



class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();

        //create a list to store the characters before the CHARACTER(ch)
        vector<char> pre;

        // suf will store the remaining suffix if there is any 
        string suf = ""; 
        
        for(int i=0; i<n; i++) {
            pre.push_back(word[i]);

            // check if the current character is the character wanted
            if(word[i] == ch) {
                // if so then put the remaining character to suf and break the loop
                suf = word.substr(i+1, n-1);
                break; 
            }
            // if the wanted character is not found, then just leave the pre empty in case it is easy to check
            if(i+1 == n) pre.clear(); 
        }
        reverse(pre.begin(), pre.end());  //reverse the pre
        string res(pre.begin(), pre.end());  //convert the pre to string res
        res+=suf; //add the remaining suf if there is any
        return pre.size() == 0 ? word : res;  //return `word` itself if pre is empty which means the wanted character is not found or return `res`
    }
};
