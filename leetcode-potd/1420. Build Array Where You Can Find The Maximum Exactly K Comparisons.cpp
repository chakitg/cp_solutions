You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:


You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.
Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
 

Constraints:

1 <= n <= 50
1 <= m <= 100
0 <= k <= n



  #define ll long long

class Solution {
public:
    int n, mod = 1e9 + 7;
    int dp[51][101][51];  // 3D array to store the dynamic programming results

    // Recursive function to calculate the number of valid arrays
    int f(int i, int prevMax, int compLeft, int &availNum) {
        if (compLeft < 0)
            return 0;
        if (i == n)
            return compLeft == 0;

        if (dp[i][prevMax][compLeft] != -1)
            return dp[i][prevMax][compLeft];  // Return the memoized result if available

        ll temp1 = 0, temp2 = 0;

        // Loop through all available numbers from 1 to availNum
        for (int num = 1; num <= availNum; num++) {
            if (num <= prevMax) {
                temp1 += f(i + 1, prevMax, compLeft, availNum);
            } else {
                temp2 += f(i + 1, num, compLeft - 1, availNum);
            }
        }

        // Memoize and return the result
        return dp[i][prevMax][compLeft] = (temp1 % mod + temp2 % mod) % mod;
    }

    int numOfArrays(int n, int m, int k) {
        this->n = n;
        int ans = 0;
        memset(dp, -1, sizeof(dp));  // Initialize the dp array with -1 (uncomputed)

        // Iterate through all possible starting numbers from 1 to m
        for (int i = 1; i <= m; i++) {
            ans = (ans % mod + f(1, i, k - 1, m) % mod) % mod;
        }

        return ans;  // Return the final result
    }
};
