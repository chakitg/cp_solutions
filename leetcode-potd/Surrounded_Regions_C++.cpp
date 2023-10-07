// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i =0; i < m; i++){
            if(board[i][0] != 'X') bfs(i, 0, board);
            if(board[i][n-1] != 'X') bfs(i, n-1, board);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] != 'X') bfs(0, j, board);
            if(board[m-1][j] != 'X') bfs(m-1, j, board);
        }
        
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
    //DFS may cause stack overflow
    void bfs(int i, int j, vector<vector<char>>& board){
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i,j));
        while(!q.empty()){
            int ii = q.front().first, jj = q.front().second;
            q.pop();
            if(ii<0 || jj<0 || ii>=board.size() || jj>=board[0].size()) continue;
            if(board[ii][jj] == 'X' || board[ii][jj] == '#') continue;
            board[ii][jj] = '#';
            q.push(pair<int, int>(ii+1, jj));
            q.push(pair<int, int>(ii-1, jj));
            q.push(pair<int, int>(ii, jj+1));
            q.push(pair<int, int>(ii, jj-1));
        }
    }
};