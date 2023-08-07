Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.


Sample Sudoku for you to get the logic for its solution:



Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
True
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Explanation: 
There exists a valid Sudoku for the input grid, which is shown in output.
Example 2:

Input:
grid[][] = 
[[3 6 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
False
Explanation: 
There does not exists a valid Sudoku for the input grid, since there are two 6s in the first row. Which cannot replaced.
Your Task:
You need to complete the two functions:

SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not, on returning false driver will print "No solution exists".

printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation. Do not give a new line character after printing the grid.

Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).

Constraints:
0 ≤ grid[i][j] ≤ 9






class Solution 
{
    bool valid(int grid[N][N], int row, int col, int filler)    {
        for (int i=0; i<N; i++) {
            if (grid[row][i]==filler)   return false;
            if (grid[i][col]==filler)   return false;
            if (grid[(row/3)*3+i/3][(col/3)*3+i%3]==filler) return false;
        }
        return true;
    }
    bool validSudoku(int grid[N][N])    {
        // below code snippet checks for any repeating number in either row or column
        for (int i=0; i<N; i++) {
            set<int> row, col;
            for (int j=0; j<N; j++) {
                if (grid[i][j]!=0)  {
                    if (!row.empty() && row.count(grid[i][j]))  return false;
                    row.insert(grid[i][j]);
                }
                if (grid[j][i]!=0)  {
                    if (!col.empty() && col.count(grid[j][i]))  return false;
                    col.insert(grid[j][i]);
                }
            }
        }
        // below code snippet checks for any repeating number in any of the 3x3 sub-grids
        for (int i=0; i<9; i++) {
            set<int> st;
            for (int j=0; j<9; j++) {
                if (grid[j/3+(i/3)*3][j%3+(i%3)*3]!=0)  {
                    if (!st.empty() && st.count(grid[j/3+(i/3)*3][j%3+(i%3)*3]))    return false;
                    st.insert(grid[j/3+(i/3)*3][j%3+(i%3)*3]);
                }
            }
        }
        return true;
    }
    public:
    // function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N], int x=1)  
    { 
        // taking a default argument x=1 because the first time function
        // call occurs from driver code, we need to check if given grid
        // is a valid sudoku in itself or not
        if (x && !validSudoku(grid)) return false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (grid[i][j]==0)  {
                    for (int filler=1; filler<=N; filler++) {
                        if (valid(grid, i, j, filler))  {
                            grid[i][j] = filler;
                            if (SolveSudoku(grid, 0))   return true;
        // passing x=0 as we need not to check again for a valid sudoku grid
                            else    grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    // function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};
