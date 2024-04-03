Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.





class Solution {
public:
        vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
        string word;
    int dfs(int x,int y,vector<vector<char>>& board,int pos)
    {
        if(pos==word.length()-1)
        return 1;
        char temp=board[x][y];
    //mark the current cell visited
        board[x][y]='#';
    //For each of the adjacent cell, call the function recursively
        for(auto u:v)
        if(x+u.first>=0&&x+u.first<board.size()&&y+u.second>=0&&y+u.second<board[0].size())
        {
            int res=0;
            if(board[x+u.first][y+u.second]==word[pos+1])
            res=dfs(x+u.first,y+u.second,board,pos+1);
        //return true if a word match is found in one of the neighbours
            if(res==1)
            return 1;
        }
    //mark the current cell unvisited
        board[x][y]=temp;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word1) {
        word=word1;
        vector<int> v(board[0].size(),0);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]&&dfs(i,j,board,0))
                return 1;
            }
        }
        return 0;
    }
};
