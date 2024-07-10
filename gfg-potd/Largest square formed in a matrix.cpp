Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: n = 2, m = 2
mat = [[0, 0], 
       [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
0 ≤ mat[i][j] ≤ 1 







class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        vector<vector<int>> dp(n,vector<int> (m,0));
        int maxi =0;
        for(int i =0;i< max(n,m);i++){
            if(i < m && mat[n -1][i] == 1){
                dp[n -1][i] =1;
                maxi =max(maxi,dp[n -1][i]);
            }
            if(i < n && mat[i][m -1] == 1){
                dp[i][m -1] =1;
                maxi =max(maxi,dp[i][m -1]);
            }
        }
        for(int i=n -2;i>=0;i--){
            for(int j =m -2;j>=0;j--){
                if(mat[i][j]){
                    dp[i][j] =1 + min(dp[i +1][j +1],min(dp[i +1][j],dp[i][j +1]));
                }else{
                    dp[i][j] =0;
                }
                maxi =max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};
