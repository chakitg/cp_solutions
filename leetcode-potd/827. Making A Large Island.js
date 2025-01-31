You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.



/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestIsland = function(grid) {
    const find_val = (ref, grid, i, j) => {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] === 0 || grid[i][j] === ref) {
            return 0;
        }
        grid[i][j] = ref;
        return 1 + (find_val(ref, grid, i + 1, j) + find_val(ref, grid, i - 1, j) + find_val(ref, grid, i, j + 1) + find_val(ref, grid, i, j - 1));
    };

    const n = grid.length;
    let ref = 2, maxArea = -1;
    const mp = new Map();

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                const k = find_val(ref, grid, i, j);
                mp.set(ref, k);
                ref += 1;
                maxArea = Math.max(maxArea, k);
            }
        }
    }

    mp.set(0, 0);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                let sum = 0;
                const seen = new Set();
                if (i > 0) seen.add(grid[i - 1][j]);
                if (j > 0) seen.add(grid[i][j - 1]);
                if (i < n - 1) seen.add(grid[i + 1][j]);
                if (j < n - 1) seen.add(grid[i][j + 1]);
                seen.forEach(val => sum += mp.get(val));
                maxArea = Math.max(maxArea, sum + 1);
            }
        }
    }
    return maxArea;
};
