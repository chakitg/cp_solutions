Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.




class Solution {
public:

    //function for counting all possible ways of forming sentence from the 
    //letters of string s from last index to index ind
    void solve(const string& s, int ind, const unordered_set<string>& wordSet, string& curr, vector<string>& result) {
        //base case when we reach the end of the string s
        if (ind == s.length()) {
            result.push_back(curr);
            return;
        }

        //running the loop from ind+1 to last index to recursively
        //add the word as part of our solution and checking further

        //loop explains that how many possible ways of forminf the setence 
        //from end to last index. Hence checking for remaining part
        for (int end = ind + 1; end <= s.length(); ++end) {
            //substring from ind of length end-ind
            string word = s.substr(ind, end - ind);

            if (wordSet.find(word) != wordSet.end()) {
                // Word is in the dictionary, then finding further outputs
                string prev = curr.empty() ? word : (curr + " " + word);
                //next call using the modified words of the string
                solve(s, end, wordSet, prev, result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //storing all out string of the dictionary in the set for further finding the
        //existence of any word in the dictonary

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //vector for storing all the answers
        vector<string> ans;

        //curr string to keep track of the sentence formed till any particular index
        string curr;

        //recursive calling of the below fxn
        //function means that how many possible ways are there constructing a
        // sentence from letters of string s from end to index  0
        solve(s, 0, wordSet, curr, ans);

        return ans;
    }
};
