Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

Example 1:

Input: 
n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}}
Output: 
{1, 0}
Explanation: 
Enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..
Example 2:

Input: 
n = 1, m = 2
matrix = {{0, 0}}
Output: 
{0, 1}
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains a 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).
Your Task:
You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and returns a list containing the exit point.

Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
Expected Space Complexity: O(1)

Constraints:
1 <= n, m <= 100









class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        pair<int,int> direction={0,1};
        int row=0, col=0;
        while(true){
            // cout<<matrix[row][col]<<" "<<row<<" "<<col<<" "<<direction.first<<" "<<direction.second<<endl;
            if(matrix[row][col]==1){
                if(direction.first==0 && direction.second==1){
                    direction.first=1;
                    direction.second=0;
                }
                else if(direction.first==1 && direction.second==0){
                    direction.first=0;
                    direction.second=-1;
                }
                else if(direction.first==0 && direction.second==-1){
                    direction.first=-1;
                    direction.second=0;
                }
                else if(direction.first==-1 && direction.second==0){
                    direction.first=0;
                    direction.second=1;
                }
                matrix[row][col]=0;
            }

            int nrow=row+direction.first;
            int ncol=col+direction.second;

            if(nrow>=n || nrow<0 || ncol>=m || ncol<0){
                return {row,col};   
            }

            row=nrow;
            col=ncol;
        }
    }
};
