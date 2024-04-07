Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.





class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();

        vector<vector<int>> cache(n+1, vector<int>(n+1 , -1));
        
        auto dp = [&](auto& dp, int i, int bal) -> bool {
            if(i >= s.length()) {
                if(bal == 0) {
                    return true;
                }
                return false;
            }
            if(bal < 0) {
                return false;
            }
            if(cache[i][bal] != -1) {
                return cache[i][bal];
            }
            bool is_good = false;
            if(s[i] == '(') {
                is_good |= dp(dp, i+1, bal+1);
            } else if (s[i] == ')') {
                is_good |= dp(dp, i+1, bal-1);
            } else if(s[i] == '*') {
                is_good |= dp(dp, i+1, bal+1);
                is_good |= dp(dp, i+1, bal-1);
                is_good |= dp(dp, i+1, bal);
            }

            
            return cache[i][bal] = is_good;
        };

        return dp(dp, 0, 0);


        
    }
};
