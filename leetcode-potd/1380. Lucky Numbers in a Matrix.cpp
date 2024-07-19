Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.





class Solution {
public:
    bool check(vector<vector<int>>& matrix, int row, int col, int p) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][col] > p) {
                return false;
            }
        }
        return true;
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> answer;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            int p = INT_MAX;
            int t;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < p) {
                    t = j;
                    p = matrix[i][j];
                }
            }
            if (check(matrix, i, t, p) == true) {
                answer.push_back(p);
            }
        }
        return answer;
    }
};

