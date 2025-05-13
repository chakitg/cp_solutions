You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105




/**
 * @param {string} s
 * @param {number} t
 * @return {number}
 */
var lengthAfterTransformations = function(s, t) {
    const MOD = 1000000007;
  const n = s.length;
  const charCounts = {};

  // Count the frequency of each character in the input string
  for (const char of s) {
    charCounts[char] = (charCounts[char] || 0) + 1;
  }

  if (t === 0) {
    return n;
  }

  const dp = Array(26).fill(0).map(() => Array(t + 1).fill(0));

  for (let i = 0; i < 26; i++) {
    dp[i][0] = 1;
  }

  for (let j = 1; j <= t; j++) {
    for (let i = 0; i < 25; i++) {
      dp[i][j] = dp[i + 1][j - 1];
    }
    dp[25][j] = (dp[0][j - 1] + dp[1][j - 1]) % MOD;
  }

  let result = 0;
  for (const char in charCounts) {
    const charCode = char.charCodeAt(0) - 'a'.charCodeAt(0);
    const frequency = charCounts[char];
    result = (result + (dp[charCode][t] * frequency) % MOD) % MOD;
  }

  return result;  
};
