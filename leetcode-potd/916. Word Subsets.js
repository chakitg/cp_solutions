You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.




  /**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function (words1, words2) {
    const result = [];
    const word2 = new Array(26).fill(0);

    for (const word of words2) {
        const temp = new Array(26).fill(0);
        for (const letter of word) {
            const index = letter.charCodeAt(0) - 97;
            temp[index]++;
        }
        for (let i = 0; i < 26; i++) {
            word2[i] = Math.max(word2[i], temp[i]);
        }
    }

    for (const word of words1) {
        const superSet = new Array(26).fill(0);
        for (const letter of word) {
            const index = letter.charCodeAt(0) - 97;
            superSet[index]++;
        }
        let isUniversal = true;
        for (let i = 0; i < 26; i++) {
            if (superSet[i] < word2[i]) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) result.push(word);
    }

    return result;
};
