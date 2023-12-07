You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.





class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int last = 0;
        bool flag = false;
        for(int i = n-1; i >= 0; i--)
            if((num[i] - '0') % 2 == 1){
                last = i;
                flag = !flag;
                break;
            }
                
        if(last == 0 && !flag) return "";
        else return num.substr(0,abs(0 - last)+1);
    }
};
