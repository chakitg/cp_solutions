Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 500



class Cell{
    public:
    int i, j, x;
    Cell(int i,int j,int x){
        this->i = i;
        this->j = j;
        this->x = x;
    }
};
class Comparator{
    public:
    int operator()(Cell& c1,Cell& c2){
        return c1.x > c2.x;
    }
};
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        priority_queue<Cell, vector<Cell>, Comparator> pq;
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        pq.push(Cell(0,0,grid[0][0]));
        dp[0][0] = grid[0][0];

        while(!pq.empty()){
            Cell temp = pq.top();
            pq.pop();
            // if(temp.i==n-1 && temp.j==m-1)  return temp.x;

            for(auto d:dir){
                int ni = d[0] + temp.i;
                int nj = d[1] + temp.j;
                if(ni<0 || nj<0 || ni>=n || nj>=m)  continue;

                int nx = grid[ni][nj] + temp.x;
                if(dp[ni][nj]<=nx) continue;
                if(ni==n-1 && nj==m-1)  return nx;

                dp[ni][nj]=nx;
                pq.push(Cell(ni,nj,nx));
            }
        }


        return 0;
    }
};
