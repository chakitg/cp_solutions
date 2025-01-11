Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105



/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    const freqMap = {};
    let singleCount = 0;

    // Count frequencies of each character
    for (const c of s) {
        freqMap[c] = (freqMap[c] || 0) + 1;
    }

    // Count how many characters have an odd frequency
    for (const freq of Object.values(freqMap)) {
        if (freq % 2 === 1) {
            singleCount++;
        }
    }

    // Check if we can construct exactly k palindromes
    return singleCount <= k && k <= s.length;
};
