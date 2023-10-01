You are given a matrix of dimensions n x m. The task is to perform boundary traversal on the matrix in a clockwise manner.

Example 1:

Input:
n = 4, m = 4
matrix[][] = {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15,16}}
Output: 1 2 3 4 8 12 16 15 14 13 9 5
Explanation:
The matrix is:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
The boundary traversal is:
1 2 3 4 8 12 16 15 14 13 9 5
Example 2:

Input:
n = 3, m = 4
matrrix[][] = {{12, 11, 10, 9},
         {8, 7, 6, 5},
         {4, 3, 2, 1}}
Output: 12 11 10 9 5 1 2 3 4 8
Your Task:
Complete the function boundaryTraversal() that takes matrix, n and m as input parameters and returns the list of integers that form the boundary traversal of the matrix in a clockwise manner.

Expected Time Complexity: O(N + M)
Expected Auxiliary Space: O(N+M)

Constraints:
1 <= n, m<= 1000
0 <= matrixi <= 1000



class Solution {
public:
    vector<int> boundaryTraversal(vector<vector<int>>& matrix, int n, int m) {
        vector<int> out;
        int i = 0, j = 0;
        for(; j < m; ++j) out.push_back(matrix[i][j]);
        ++i; --j;
		
        if(n > 1) {
            for(; i < n; ++i) out.push_back(matrix[i][j]);
            --i; --j;
			
            if(m > 1) {
                for(; j >= 0; --j) out.push_back(matrix[i][j]);
                --i; ++j;
				
                for(; i > 0; --i) out.push_back(matrix[i][j]);
            }
        }
        return out;
    }
};
