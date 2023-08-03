Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.



class Solution {
public:
    bool ok(int x, vector<int> &a) {
        long long remove = 0;
        for(auto t : a) {
         if(t < x) {
            remove += (x-t);
         } else {
            int need = (t - x);
            if(need > remove) return 0;
            remove -= need;
         }
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& a) {
      int l = -1;
      int r = 1e9;
      while(r > l + 1) {
        int m = (l+r) >> 1;
        if(ok(m,a)) {
          r = m;
        } else  {
          l = m;
        }
      }
      return r;
    }
};
