You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 

Constraints:

3 <= num.length <= 1000
num only consists of digits.





class Solution {
public:
    string largestGoodInteger(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        string ans = "";
        int count = 1;
        char res = 'a';
        char prev = num[0];
        for(int i = 1; i < num.length(); i++)
        {
            char curr = num[i];
            if(curr == prev) count++;
            else
            {
                prev = curr;
                count = 1;
            }
            if(count == 3 and res == 'a') res = prev;
            else if(count == 3 and res != 'a')
            {
                if(res < prev) res = prev;
            }
        }
        if(res == 'a') return "";
        for(int i = 0; i < 3; i++) ans.push_back(res);
        return ans;
    }
};
