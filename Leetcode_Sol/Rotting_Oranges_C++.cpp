// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m= grid[0].size();
        //4- directionally
        int dx[4]={0,1,0,-1};
        int dy[4]={-1,0,1,0};
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                // Push Rottan oranges into queue to do BFS(Layer by Layer)
                if(grid[i][j]==2)     q.push({i,j});
                //Counting number of fresh oranges.
                if(grid[i][j]==1) fresh++;      
            }
        }
        int days=0;
        while(!q.empty() and fresh){
            days++;
            int levelNodes=q.size();
            while(levelNodes--){
                pair<int,int> f=q.front();
                q.pop();
                int x=f.first,y=f.second;
                for(int i=0;i<4;i++){
               int     X=x+dx[i],Y=y+dy[i];
                    if((X>=0 and X<n) and (Y>=0 and Y<m) and grid[X][Y]==1){
                        fresh--;
                        grid[X][Y]=2;
                        q.push({X,Y});
                    }
              }
            }
            
        }
        //If you made all fresh oranges to rotten, return days or -1
        return (fresh==0)?days:-1;
    }
};