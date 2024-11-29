Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106




class Solution
{
public:
    string addBinary(string &s1, string &s2)
    {
        // your code here
        string res = "";
        int n = s1.size(), m = s2.size();
        int i = n - 1, j = m - 1;
        int prev = 0;
        while (i >= 0 && j >= 0)
        {
            prev += s1[i] - '0' + s2[j] - '0';
            res += to_string(prev % 2);
            prev /= 2;
            i--, j--;
        }
        while (i >= 0)
        {
            prev += s1[i] - '0';
            res += to_string(prev % 2);
            prev /= 2;
            i--;
        }
        while (j >= 0)
        {
            prev += s2[j] - '0';
            res += to_string(prev % 2);
            prev /= 2;
            j--;
        }
        if (prev)
            res += "1";
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
