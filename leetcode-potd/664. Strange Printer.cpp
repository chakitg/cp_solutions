There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.



class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    // Helper function to find the minimum number of operations required to print substring s[i...j]
    int f(int i, int j, string& s){       
        // If dp[i][j] has already been calculated, return its value to avoid recomputation.
        if (dp[i][j]!=-1) return dp[i][j];
        
        // initial case: When i=j, it only takes 1 operation to print it.
        if (i==j) return dp[i][j]=1;
        
        int ans; // Variable to store the minimum number of operations required to print substring s[i...j].
        
        // If s[i]==s[j] or s[j]==s[j-1],
        // then it's equivalent to printing substring s[i...j-1].
        if (s[i]==s[j]||s[j-1]==s[j]) ans=f(i, j-1, s);
        
        // If s[i]==s[i+1], it's equivalent to printing substring s[i+1...j].
        else if (s[i]==s[i+1]) ans=f(i+1, j, s);
        
        // If the above two conditions are not met, it means that s[i] and s[j] are different, and s[j] is also different 
        // from the character before it. In this case, we have multiple options:
        else{
            // Option 1: Print s[i...j-1] and then the character at position j, so the number of operations is f(i,j-1,s) + 1.
            ans=f(i,j-1, s)+1;
            
            // Option 2: We can try to find a character k between i and j (exclusive) such that s[k] is the same as s[j].
            // If we find such a character, it means we can print s[i...k-1] and s[k...j-1] together as one operation,
            // since both sequences will end with the same character s[j]. The number of operations would be f(i,k-1,s) + f(k,j-1,s).
            // We try all possible k values and choose the minimum among them.
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    ans=min(ans, f(i, k-1, s)+f(k, j-1, s));
            }
        }
        // Save the computed result in dp table to avoid recomputation for the same subproblems.
        return dp[i][j]=ans;
    }
    
    int strangePrinter(string s) {
        n=s.size(); // Get the size of the input string.
        dp.assign(n, vector<int>(n, -1)); // Initialize the dp table with -1 to mark that no subproblem has been computed yet.
        return f(0, n-1, s); // Call the helper function to find the minimum number of operations to print the entire string.
    }
};




----------------------------------------------------------------------------- 




 class Solution {
public:
    int n;
    int dp[101][101];
    int rec(string&s , int l , int r){
        if(l==r) return 1;
        if(l>r)  return 0;
        if(~dp[l][r]) return dp[l][r];

        int i = l+1;
        while(i<=r && s[i]==s[l]) i++;
        if(i == r+1) return dp[l][r]=  1;

        int basic = 1 + rec(s , i , r);

        int greedy = INT_MAX;

        for(int j = i ; j<=r ; j++){
            if(s[j]==s[l]){
                // 1 + kyo ni kara is the main catch
                int ans = rec(s, i , j-1) + rec(s , j , r);
                greedy = min(ans , greedy);
            }
        }
        return dp[l][r] = min(greedy , basic);
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        n = s.size();
        return rec(s,  0 , n-1);
    }
};
