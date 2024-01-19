Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100




class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(N+2, vector<int>(N+2, INT_MAX));
        
        //dp: wrap A with a margin of width 1
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i+1][j+1] = A[i][j];
            }
        }
        
        //skip last row
        for(int row = N-1; row >= 1; row--){ //[0,N-2]+1
            for(int col = 1; col <= N; col++){ //[0,N-1]+1
                dp[row][col] += min({dp[row+1][col-1], dp[row+1][col], dp[row+1][col+1]});
            }
        }
        
        return *min_element(dp[1].begin(), dp[1].end());
    }
};
