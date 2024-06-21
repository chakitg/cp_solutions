You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

Examples

Input: str = "5/6, 11/45"
Output: 5/6
Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
Input: str = "8/1, 8/1"
Output: equal
Explanation: We can see that both the fractions are same, so we'll return a string "equal".
Input: str = "10/17, 9/10"
Output: 9/10
Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
Expected Time Complexity: O(len|str|)
Expected Auxiliary Space: O(1)

Constraints:
0<=a,c<=103
1<=b,d<=103









class Solution {
public:
    string compareFrac(string& s) {
        int n = s.length();
        int a = 0, b = 0, c = 0, d = 0;
        int i = 0;
        while (i < n && s[i] != '/') {
            a = a * 10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < n && s[i] != ',') {
            b = b * 10 + s[i] - '0';
            i++;
        }
        i += 2; // Skip ", "
        while (i < n && s[i] != '/') {
            c = c * 10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < n) {
            d = d * 10 + s[i] - '0';
            i++;
        }
        if ((a * d) > (b * c)) {
            return to_string(a) + "/" + to_string(b);
        } else if ((a * d) < (b * c)) {
            return to_string(c) + "/" + to_string(d);
        }
        return "equal";
    }
};
