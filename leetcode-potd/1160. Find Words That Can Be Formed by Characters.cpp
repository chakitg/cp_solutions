You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int>cnt(26,0);
        for(auto x : chars) {
            cnt[x-'a']++;
        }
        for(auto s : words) {
          vector<int>c(26,0);
          for(auto x : s) {
            c[x-'a']++;
          }
          bool ok = 1;
          int n = (int)s.size();
          for(int i = 0 ; i < 26 ; i++) {
            if(cnt[i] < c[i]) ok = 0;
          }
          if(ok) {
            ans += n;
          }
        }
        return ans;
    }
};


___________________________________________________________________________________


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        map<char, int> ss;
        for(int i = 0; i < chars.length(); i++)
            ss[chars[i]]++;
        for(int i = 0; i < words.size(); i++)
        {
            int count = 0;
            map<char, int> mp = ss;
            for(int j = 0; j < words[i].length(); j++)
            {
                if((mp.find(words[i][j]) != mp.end()) && mp[words[i][j]] != 0){
                    mp[words[i][j]]--;
                    count++;
                }      
            }
            if(count == words[i].length())
                ans += count;
        }
        return ans;
    }
};
