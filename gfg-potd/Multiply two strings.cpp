Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253
Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

Constraints:
1 ≤ length of s1 and s2 ≤ 103



class Solution {
public:
    string multiplyStrings(string s1, string s2) {
        if(s1 == "0" || s2 == "0") return "0";
        
        int neg = 1;
        // Checking for negative signs
        if(s1[0] == '-') {
            s1 = s1.substr(1);
            neg *= -1;
        }

        if(s2[0] == '-') {
            s2 = s2.substr(1);
            neg *= -1;
        }
        
        int n1 = s1.size(), n2 = s2.size();
        string ans(n1 + n2, '0');
        
        for(int i = n2 - 1; i >= 0; i--) {
            int carry = 0;
            // Multiplying s2 with each digit
            for(int j = n1 - 1; j >= 0; j--) {
                int pdt = (s1[j] - '0') * (s2[i] - '0') + (ans[i + j + 1] - '0') + carry;
                carry = pdt / 10;
                ans[i + j + 1] = (pdt % 10) + '0';
            }
            ans[i] += carry;
        }
        
        int start = 0;
        while(start < ans.size() - 1 && ans[start] == '0')
            start++;
        ans = ans.substr(start);
        
        if(neg == -1 && ans != "0")
            ans = "-" + ans;

        return ans;
    }
};
