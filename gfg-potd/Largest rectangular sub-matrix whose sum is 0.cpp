Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
Your Task:
You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

Expected Time Complexity: O(N*M*M).
Expected Auxiliary Space: O(N*M).


Constraints:
1 <= N, M <= 100
-1000 <= mat[][] <= 1000






class Solution {
public:
    struct cood {
        int x1, y1, x2, y2;
    };

    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> pre = a;

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pre[i][j] += pre[i - 1][j];

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                pre[i][j] += pre[i][j - 1];

        cood nax = { -1, -1, -1, -1 };
        int area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0;
                if (i > 0 && j > 0)
                    sum += pre[i - 1][j - 1];

                for (int y = m - 1; y >= j; --y) {
                    for (int x = n - 1; x >= i; --x) {
                        if (area <= (x - i + 1) * (y - j + 1)) {
                            int s = sum + pre[x][y];
                            if (i > 0)
                                s -= pre[i - 1][y];
                            if (j > 0)
                                s -= pre[x][j - 1];

                            if (s == 0) {
                                if (area != (x - i + 1) * (y - j + 1)) {
                                    area = (x - i + 1) * (y - j + 1);
                                    nax = { i, j, x, y };
                                }
                                else {
                                    if (nax.y1 > j) {
                                        area = (x - i + 1) * (y - j + 1);
                                        nax = { i, j, x, y };
                                    }
                                    else if (nax.y1 == j) {
                                        if (nax.x2 - nax.x1 < x - i) {
                                            area = (x - i + 1) * (y - j + 1);
                                            nax = { i, j, x, y };
                                        }
                                    }
                                }
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }

        vector<vector<int>> out;
        if (area == 0)
            return out;

        for (int i = nax.x1; i <= nax.x2; ++i) {
            vector<int> arr;
            for (int j = nax.y1; j <= nax.y2; ++j) {
                arr.push_back(a[i][j]);
            }
            out.push_back(arr);
        }
        return out;
    }
};
