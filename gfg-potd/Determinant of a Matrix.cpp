Given a square matrix of size n*n. The task is to find the determinant of this matrix.

Example 1:

Input:
n = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
Output: 30
Explanation:
Determinant of the given matrix is 30.
Example 2:

Input:
n = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6},
              {7, 10, 9}}
Output: 12
Explanation:
Determinant of the given matrix is 12.
Your Task:
You don't need to read input or print anything. Complete the function determinantOfMatrix() that takes matrix and its size n as input parameters and returns the determinant of the matrix.

Expected Time Complexity: O(N4)
Expected Auxiliary Space: O(N2)

Constraints:
1 <= N <= 10
-10 <= mat[i][j] <= 10




class Solution {
public:
    int determinantOfMatrix(vector<vector<int>> mat, int n) {
        if (n == 1) {
            return mat[0][0];
        }
        if (n == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }

        int sign = 1, ans = 0;
        vector<vector<int>> m(n - 1, vector<int>(n - 1));

        for (int row = 0; row < n; ++row) {
            int k = 0;
            for (int i = 0; i < n; ++i) {
                if (i != row) {
                    for (int j = 1; j < n; ++j)
                        m[k][j - 1] = mat[i][j];

                    k++;
                }
            }
            ans += sign * (mat[row][0]) * determinantOfMatrix(m, n - 1);
            sign *= -1;
        }
        return ans;
    }
};
