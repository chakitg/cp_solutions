Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4



class Solution {
public:
    int countVowelPermutation(int n) {
        long long prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;
        int mod = 1e9 + 7; // Modulo value to handle large numbers

        for (int length = 2; length <= n; length++) {
            // Calculate the next values for each vowel following the rules
            long long nextA = (prevE + prevU + prevI) % mod; // 'a' can be preceded by 'e', 'u', or 'i'
            long long nextE = (prevA + prevI) % mod; // 'e' can be preceded by 'a' or 'i'
            long long nextI = (prevE + prevO) % mod; // 'i' can be preceded by 'e' or'o'
            long long nextO = prevI; // 'o' can only be preceded by 'i'
            long long nextU = (prevO + prevI) % mod; // 'u' can be preceded by 'o' or 'i'

            // Update the previous values for the next iteration
            prevA = nextA;
            prevE = nextE;
            prevI = nextI;
            prevO = nextO;
            prevU = nextU;
        }

        // Return the sum of all vowel counts modulo the defined value
        return (prevA + prevE + prevI + prevO + prevU) % mod;
    }
};
