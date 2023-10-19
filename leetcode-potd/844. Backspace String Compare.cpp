Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.





class Solution {
public:
    string loopCheck(string str) {
        string res = "";
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '#' && !res.empty()) res.erase(res.size()-1);
            else if(str[i]!='#') res = res + str[i];
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return (loopCheck(s) == loopCheck(t)) ? true: false;
    }
};
  
