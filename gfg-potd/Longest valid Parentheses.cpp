Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105  




class Solution {
  public:
    int maxLength(string& str) {
        int ans=0,op=0,cl=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(') op++;
            else cl++;
            if(cl>op) op=cl=0;
            if(cl==op) ans=max(ans,cl*2);
        }
        op=cl=0;
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='(')op++;
            else cl++;
            if(cl<op) op=cl=0;
            if(cl==op) ans=max(ans,cl*2);
        }
        return ans;
    }
};
