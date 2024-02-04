Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.





class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        // This is the common sliding window problem

        unordered_map<char,int> mp2;            // Storing values of string 't'
        string ans;
        for(auto x:t)
        {
            mp2[x]++;
        }

        unordered_map<char,int> mp;
        int mini = INT_MAX;

        int i=0,j=0;
        while(j<n)
        {
            mp[s[j]]++;
            
            int flag = 0;
            for(auto x:mp2)             // Checking if all values of mp2 are in mp1.
            {
                if(mp2[x.first]>mp[x.first])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag==0)                 // If matches, then find min by decreasing the string 's'
            {
                while(mp[s[i]]>mp2[s[i]])
                {
                    mp[s[i]]--;

                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if(mini>j-i+1)
                {
                    mini = min(mini,j-i+1);
                    ans = s.substr(i,j-i+1);
                }
            }

            j++;
        }
        return ans;
    }
};
