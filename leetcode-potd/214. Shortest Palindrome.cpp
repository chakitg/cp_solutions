You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.



class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s+"@"+rev;

        //now we find lps array
        int n = str.length();
        vector<int> lps(n, 0);
        int i = 0; 
        for (int j = 1; j < n; ) {
            if (str[i] == str[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i != 0) {
                    i = lps[i - 1]; // fall back to prev lps
                } else {
                    lps[j] = 0; // no prefix match move forward
                    j++;
                }
            }
        }
        // cout<<str<<endl;
        // for(auto it: lps) cout<<it<<" ";
        // cout<<endl<<i<<endl;
        string temp = s.substr(i);
        // cout<<temp;
        reverse(temp.begin(), temp.end());
        return temp+s;
    }
};
