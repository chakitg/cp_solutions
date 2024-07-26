Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  

Constraints:
1<= str.size() <= 105
0<= k <= 50
str may contain duplicate characters
str contains only lowercase alphabets or spaces.




class Solution {
    public:
    bool kPangram(string str, int k) {
        unordered_map<int,int> mp;
        for(auto& it:str)
        mp[it]++;

        int need;
        int distChar;
        if(mp.count(' '))
        {
            distChar=mp.size()-1;
            need=26-distChar;
        }
        else
        {
            distChar=mp.size();
            need=26-distChar;
        }

        if(need<=k and (str.length()-mp[' ']-distChar)>=need)
        return true;
        else
        return false;
    }
};
