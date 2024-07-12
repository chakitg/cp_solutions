You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.





class Solution {
    int solve(string &s,string priority){
        int n=s.size();
        int count=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==priority[1] && st.top()==priority[0] ){
                st.pop();
                count++;

            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return count;
    }
public:
    int maximumGain(string s, int x, int y) {
        string l="";
        string h="";
        if(y>x){
            l="ab";
            h="ba";
            swap(x,y);
        }else{
            l="ba";
            h="ab";
        }
        int a=solve(s,h)*x; //high 15
        int b=solve(s,l)*y; //low
        return a+b;
    }
};
