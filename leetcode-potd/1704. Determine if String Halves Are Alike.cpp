You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.





class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int>mp;
        vector<char>a = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        for(auto x : s) {
            for(auto t : a) {
                if(x == t) cnt++;
            }
        }
        int have = 0;
        for(int i = 0 ; i < (int)s.size()/2 ; i++) {
            for(auto t : a) {
                if(s[i] == t) have++;
            }
        }
        if(have == cnt - have) {
            return 1;
        }
        return 0;
    }
};



// ----------------------------------------------------------------------------------


class Solution {
public:
    bool halvesAreAlike(string s) {
        int countLeftVowel = 0, countRightVowel = 0;
        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            countLeftVowel++;
        }
        for (int i = s.length()/2; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            countRightVowel++;
        }
        if (countLeftVowel == countRightVowel)
            return true;
        return false;
    }
};
