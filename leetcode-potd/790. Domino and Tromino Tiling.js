You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000



/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function (n) {
    const MOD = 1e9 + 7;
    if (n === 1) return 1;
    if (n === 2) return 2;

    const dp = new Array(n + 1).fill(0);
    dp[0] = 1;  // 1 way to fill empty board
    dp[1] = 1;  // 1 way for n = 1 (vertical domino)
    dp[2] = 2;  // 2 ways for n = 2 (two vertical dominos OR two horizontal dominos)

    for (let i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }

    return dp[n];
};
