Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.


class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        int mostFreq =0, i=0;

        for(char c: s){
            if(++cnt[c-'a'] > cnt[mostFreq]) mostFreq = (c-'a');
        }
        if(2*cnt[mostFreq]-1 > s.size()) return "";

        while(cnt[mostFreq]){
            s[i] = ('a' + mostFreq);
            cnt[mostFreq]--;
            i+=2;
        }

        for(int j=0; j<26; j++){
            while(cnt[j]){
                if(i >= s.size()) i=1;
                s[i] = ('a' + j);
                cnt[j]--;
                i+=2;
            }
        }

        return s;
    } 
};
