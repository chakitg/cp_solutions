Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: 
S = "aebcbda"
Output: 
2
Explanation: 
Remove characters 'e' and 'd'.
Example 2:

Input: 
S = "geeksforgeeks"
Output: 
8
Explanation: 
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103




class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int max_len=1, st=0;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=i ; j<n ; j++){
                if(i==j){
                    dp[i][j]=1;
                }else if(j-i==1){
                    dp[i][j] = s[i]==s[j];
                }else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && max_len < j-i+1){
                    st=i;
                    max_len = j-i+1;
                }
            }
        }
        return s.substr(st, max_len);
    }
};
