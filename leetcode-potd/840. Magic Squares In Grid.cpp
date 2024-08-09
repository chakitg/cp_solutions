A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15








  class Solution {
public:
// total sum of a magic grid will always be 45
// therefore sum of each row, column, diagonal will be 15 
// there are limited formations such that the sum of each row, column and diagonal is 15
// there will be 8 such formations and the formations will have 2 things in common 
// the middle element is always 5 and rest elements are a subset of  org or revformat(check code)
    bool is_valid(vector<vector<int>>matrix, int ii, int jj){
        if(ii+2>=matrix.size() || jj+2>=matrix[0].size()) return false;
        if(matrix[ii+1][jj+1]!=5) return false; 
        string traversal="";
        string org="2943816729438167";
        string revorg="761834927618349";
        // circular traversal
        traversal += to_string(matrix[ii][jj]); 
        traversal += to_string(matrix[ii][jj + 1]); 
        traversal += to_string(matrix[ii][jj + 2]); 
        traversal += to_string(matrix[ii + 1][jj + 2]);  
        traversal += to_string(matrix[ii + 2][jj + 2]);  
        traversal += to_string(matrix[ii + 2][jj + 1]); 
        traversal += to_string(matrix[ii + 2][jj]);  
        traversal += to_string(matrix[ii + 1][jj]);
        return (org.find(traversal) != string::npos || revorg.find(traversal) != string::npos);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int cnt=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(is_valid(grid,i,j)) cnt++;
            }
        }
        return cnt;
    }
};
