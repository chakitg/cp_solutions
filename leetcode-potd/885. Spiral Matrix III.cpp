You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols





class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // To store the path of cells visited
        vector<vector<int>> paths;
        // Start from the initial position
        paths.push_back({rStart, cStart});

        // Directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int steps = 0, direction = 0;

        // Loop until all cells are visited
        while (paths.size() != rows * cols) {

            // Increase steps after completing a right or left move
            if (direction == 0 || direction == 2) {
                steps++;
            }

            // Move `steps` number of cells in the current direction
            for (int i = 0; i < steps; i++) {
                rStart += directions[direction].first;
                cStart += directions[direction].second;

                // Check if the new position is within the bounds of the matrix
                if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols) {
                    paths.push_back({rStart, cStart});
                }
            }

            // Move to the next direction in the sequence
            direction = (direction + 1) % 4;
        }

        return paths;
    }
};
