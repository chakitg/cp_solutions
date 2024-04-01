Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.




class Solution {
public:
    int lengthOfLastWord(string s) {
       stack<char> st;
       int x=0;
        int n = s.length();
       while(s[n] == ' '){
           n--;
       }
       for(int i=s.length()-1; i>=0; i--){
           char ch  = s[i];

           if(s[i]!=' '){

               st.push(ch);
           }
           else if(s[i]==' ' && !st.empty()){
            
              break;
               
           } 
       }
        x = st.size();
        
       return x;
        
    }
};
