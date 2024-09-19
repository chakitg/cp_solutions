Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105



class Solution
{
public:
    string reverseWords(string str)
    {
        // code here
        int n = str.length();
        stack<string> st;
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (str[j] != '.' && j < n)
            {
                temp += str[j];
                j++;
            }
            st.push(temp);
            temp = "";
            i = j;
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (!st.empty())
                res += '.';
        }
        return res;
    }
};
