Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.

Note: Both the strings contain only lowercase letters.

Examples:

Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times (wwww), s2 is a substring of it.
Input: s1 = "abcd", s2 = "cdabcdab" 
Output: 3 
Explanation: Repeating s1 three times (abcdabcdabcd), s2 is a substring of it. s2 is not a substring of s2 when it is repeated less than 3 times.
Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.
Constraints:
1 ≤ |s1|, |s2| ≤ 105



class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string temp=s1;
        int count=1;
        while(s1.size()<s2.size())
        {
            s1=s1+temp;
            count++;
            
        }
        if(s1.find(s2)!=-1)return count;
        s1=s1+temp;
        count++;
        if(s1.find(s2)!=-1)return count;
        return -1;
        
    }
};
