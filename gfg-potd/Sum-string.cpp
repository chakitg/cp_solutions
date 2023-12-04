Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it.

Example 1:

Input:
S = "12243660"
Output:
1
Explanation:
"12243660" can be broken down as {"12", "24", "36", "60"}.
We can get 60 from 24 and 36 as 24 + 36 = 60. Similarly 36 can be written as 12 + 24.
Example 2:

Input:
1111112223
Output:
1
Explanation:
"1111112223" can be broken down as {"1", "111", "112", "223"}.
We can get 223 from 111 and 1112 as 111 + 112 = 223. Similarly 112 can be written as 1 + 111.
Your Task:

You don't need to read input or print anything. Your task is to complete the function isSumString() which takes the string S and returns 1 is S is a sum-string otherwise returns 0.

Expected Time Complexity: O(|S|3)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <= 500
String consists of characters from '0' to '9'.








class Solution {
public:
    string add(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res;

        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
            --j;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --j;
        }
        if (carry)
            res += carry + '0';
            
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool solve(string& s, int i, int j, int k) {
        string num1 = s.substr(i, j - i);
        string num2 = s.substr(j, k - j);
        string sum = add(num1, num2);

        int n = sum.size();
        int len = k + n;

        if (len > s.size())
            return false;

        string currSum = s.substr(k, n);

        if (currSum != sum)
            return false;
        if (len == s.size())
            return true;
        return solve(s, j, k, len);
    }

    int isSumString(string& s) {
        int n = s.size();
    
        for (int j = 1; j < n; ++j) 
            for (int k = j + 1; k < n; ++k) 
                if (solve(s, 0, j, k))
                    return true;

        return false;
    }
};
