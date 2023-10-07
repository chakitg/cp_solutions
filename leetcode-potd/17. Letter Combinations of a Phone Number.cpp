Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        unordered_map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        string currentCombination;
        backtrack(digits, 0, mapping, currentCombination, result);
        
        return result;
    }
    
    void backtrack(const string& digits, int index, const unordered_map<char, string>& mapping, string& currentCombination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        char digit = digits[index];
        string letters = mapping.at(digit);
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, mapping, currentCombination, result);
            currentCombination.pop_back(); // Backtrack by removing the last letter added
        }
    }
};
