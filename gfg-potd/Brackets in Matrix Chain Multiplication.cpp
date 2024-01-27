Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
Example 1:

Input: 
n = 5
p[] = {40, 20, 30, 10, 30}
Output: 
True
Explaination: 
Let's divide this into matrix(only 4 are possible) 
[ [40, 20] -> A
, [20, 30] -> B
, [30, 10] ->C
, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC)
then we multiply A to (BC) -> (A(BC))
then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
Example 2:

Input: 
n = 3
p = {3, 3, 3}
Output: 
True
Explaination: 
The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.
Your Task:
You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
2 ≤ n ≤ 26 
1 ≤ p[i] ≤ 500 





class Solution {
public:
    string matrixChainOrder(int p[], int n) {
        pair<int, string> dp[n][n];

        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (gap == 1) {
                    string res = "0";
                    res[0] = 'A' + i;
                    dp[i][j] = {0, res};
                } else {
                    dp[i][j] = {INT_MAX, "-1"};
                    for (int k = i + 1; k <= j - 1; k++) {
                        int cost = p[i] * p[k] * p[j] + dp[i][k].first + dp[k][j].first;
                        if (dp[i][j].first > cost) {
                            dp[i][j].first = cost;
                            dp[i][j].second = "(" + dp[i][k].second + dp[k][j].second + ")";
                        }
                    }
                }
            }
        }

        return dp[0][n - 1].second;
    }
};
