You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var countOfSubstrings = function (word, k) {
    let startIndex = 0, endIndex = 0;
    let ob = ['a', 'i', 'o', 'u', 'e'];
    let consonentCount = 0;
    let result = 0;
    let count = 0;
    const map = new Map();
    while (endIndex < word.length) {
        if (ob.includes(word[endIndex])) {
            map.set(word[endIndex], (map.get(word[endIndex]) || 0) + 1);
        } else if (word[endIndex]) {
            consonentCount++;
        }
        while (consonentCount > k) {
            if (ob.includes(word[startIndex])) {
                map.set(word[startIndex], map.get(word[startIndex]) - 1);
                if (!map.get(word[startIndex])) {
                    map.delete(word[startIndex])
                }
            } else {
                consonentCount--;
            }
            startIndex++;
        }
        while (map.size === 5 && consonentCount === k) {
            if (ob.includes(word[startIndex])) {
                map.set(word[startIndex], map.get(word[startIndex]) - 1);
                if (!map.get(word[startIndex])) {
                    map.delete(word[startIndex])
                }
            } else {
                consonentCount--;
            }
            count++;
            startIndex++;
        }
        result += count;
        endIndex++;
        if (word[endIndex] && !ob.includes(word[endIndex])) {
            count = 0;
        }
    }
    return result;
};
