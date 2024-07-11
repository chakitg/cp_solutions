You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.







class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                int start = st.top()+1;
                int end = i;

                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }

        for(auto &ch : s)
        {
            if(ch != '(' && ch != ')')
            {
                ans += ch;
            }
        }

        return ans;
    }
};
