You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.





class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        vector<vector<int>> dp(str1.size(), vector<int> (str2.size(), -1));
        int maxS = 0;
        for(int i=0; i<str1.size(); i++){
            for(int j=0; j<str2.size(); j++){
                if(str1[i] == str2[j] && dp[i][j] == -1){
                    int k=i, l=j;
                    while(k<str1.size() && l<str2.size() && str1[k] == str2[l]){
                        dp[k][l] = 1;
                        k++;
                        l++;
                    }
                    maxS = max(maxS, l-j);
                }
            }
        }
        return maxS;
    }
};
