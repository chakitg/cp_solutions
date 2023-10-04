Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999




class Solution {
public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> mp;
        mp['I'] = 1; 
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = str.size();
        
        int out = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[str[i]] < mp[str[i + 1]])
                out -= mp[str[i]];
            else
                out += mp[str[i]];
        }
        
        return out;
    }
};
