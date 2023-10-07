// The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

// Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "aababbb"
// Output: 3
// Explanation:
// All possible variances along with their respective substrings are listed below:
// - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
// - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
// - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
// - Variance 3 for substring "babbb".
// Since the largest possible variance is 3, we return it.
// Example 2:

// Input: s = "abcde"
// Output: 0
// Explanation:
// No letter occurs more than once in s, so the variance of every substring is 0.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.






class Solution {
public:
    int largestVariance(string s) {
        int count1 = 0;
        int count2 = 0;
        int max_variance = 0;

        // Create a distinct set of character pairs
        unordered_set<char> distinct_chars(s.begin(), s.end());

        // Run once for original string order, then again for reverse string order
        for (int runs = 0; runs < 2; runs++) {
            for (char l1 : distinct_chars) {
                for (char l2 : distinct_chars) {
                    if (l1 == l2) {
                        continue;
                    }
                    count1 = count2 = 0;
                    for (char letter : s) {
                        if (letter == l1) {
                            count1++;
                        } else if (letter == l2) {
                            count2++;
                        }
                        if (count1 < count2) {
                            count1 = count2 = 0;
                        } else if (count1 > 0 && count2 > 0) {
                            max_variance = max(max_variance, count1 - count2);
                        }
                    }
                }
            }

            // Reverse the string for the second time around
            reverse(s.begin(), s.end());
        }

        return max_variance;
    }
};
