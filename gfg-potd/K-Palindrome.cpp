Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.


Example 1:

Input: str = "abcdecba"
n = 8, k = 1
Output: 1
Explaination: By removing 'd' or 'e' 
we can make it a palindrome.

Example 2:

Input: str = "abcdefcba"
n = 9, k = 1
Output: 0
Explaination: By removing a single 
character we cannot make it a palindrome.

Your Task:
You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.


Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ n, k ≤ 103





  class Solution{
public:
  vector<vector<int>> memo;
    int minDeletions(int l, int r, const string& str) {

        if (l >= r) 
        {
            return 0;
        }
        if (memo[l][r] != -1) 
        {
            return memo[l][r];
        }
        if (str[l] == str[r]) 
        {
            memo[l][r] = minDeletions(l + 1, r - 1, str);
        } 
        else 
        {
            memo[l][r] = 1 + min(minDeletions(l + 1, r, str), minDeletions(l, r - 1, str));
        }
        return memo[l][r];
    }
    int kPalindrome(string str, int n, int k)
    {
        memo.resize(n, vector<int>(n, -1));
        return minDeletions(0, n - 1, str)<=k ;
    }
};
