Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.






class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        // Unordered map to store anagram groups
        unordered_map<string, vector<string>> anagramGroups;
        
        // Iterate through each word in the input vector
        for (const string& word : words) {
            // Sort the characters in the word to create a key
            string key = word;
            sort(key.begin(), key.end());
            
            // If key is not in the map, add a new entry with the word as a vector
            if (anagramGroups.find(key) == anagramGroups.end()) {
                anagramGroups[key] = {word};
            }
            // If key is already present, append the word to the existing vector
            else {
                anagramGroups[key].push_back(word);
            }
        }
        
        // Convert map values to a vector and return
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
