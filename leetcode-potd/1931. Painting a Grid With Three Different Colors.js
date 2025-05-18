You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.
Example 2:


Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
Example 3:

Input: m = 5, n = 5
Output: 580986
 

Constraints:

1 <= m <= 5
1 <= n <= 1000

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
const MOD = 1e9 + 7;

// Generate all valid row patterns of length m
function generateRowPatterns(m) {
  const colors = [0, 1, 2]; // 0 = red, 1 = green, 2 = blue
  const result = [];

  function backtrack(pos, curr) {
    if (pos === m) {
      result.push([...curr]);
      return;
    }
    for (const color of colors) {
      if (pos > 0 && curr[pos - 1] === color) continue;
      curr.push(color);
      backtrack(pos + 1, curr);
      curr.pop();
    }
  }

  backtrack(0, []);
  return result;
}

// Check vertical compatibility between two row patterns
function areCompatible(a, b) {
  for (let i = 0; i < a.length; i++) {
    if (a[i] === b[i]) return false;
  }
  return true;
}

function colorTheGrid(m, n) {
  const rows = generateRowPatterns(m);
  const rowCount = rows.length;

  // Build compatibility map
  const compat = new Map();
  for (let i = 0; i < rowCount; i++) {
    compat.set(i, []);
    for (let j = 0; j < rowCount; j++) {
      if (areCompatible(rows[i], rows[j])) {
        compat.get(i).push(j);
      }
    }
  }

  // Initialize DP: dp[col][rowIndex] = number of ways
  let dp = new Array(rowCount).fill(1); // First column: all valid patterns count as 1

  for (let col = 1; col < n; col++) {
    const newDp = new Array(rowCount).fill(0);
    for (let curr = 0; curr < rowCount; curr++) {
      for (const prev of compat.get(curr)) {
        newDp[curr] = (newDp[curr] + dp[prev]) % MOD;
      }
    }
    dp = newDp;
  }

  // Sum all ways in the last column
  return dp.reduce((sum, val) => (sum + val) % MOD, 0);
}
