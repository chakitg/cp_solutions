// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

// In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

// Example 1:


// Input: n = 3
// Output: 5
// Explanation: The five different ways are show above.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 1000


//______________________________________________________________________________________________________________



class Solution {
public:
    int numTilings(int N) {
    vector<vector<int>> T{{1, 0, 0, 1},  // #(|) = #(|) + #(=)
                              {1, 0, 1, 0},  // #(「) = #(|) + #(L)
                              {1, 1, 0, 0},  // #(L) = #(|) + #(「)
                              {1, 1, 1, 0}}; // #(=) = #(|) + #(「) + #(L)
        return matrixMult({{1, 0, 0, 0}}, matrixExpo(T, N))[0][0];  // [a0, a(-1), a(-2), a(-3)] * T^N
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % M + entry) % M;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
    const int M = 1e9 + 7;
};