Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).
Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

Constraints:
1 <= N,M <= 250
0 <= X < N
0 <= Y < M
0 <= A[i][j] <= 1




class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[0][0]!=1 || A[X][Y]!=1)
        return -1;
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        int dis=0;
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0]=1;
        
        while(!q.empty())
        {
            int s=q.size();
            
            for(int i=0;i<s;i++)
            {
                int x=q.front()[0];
                int y= q.front()[1];
                q.pop();
                if(x==X && y==Y)
                    return dis;
                
                int dirs[4][4]= {{-1,0},{1,0},{0,-1},{0,1}};
                for(int i=0;i<4;i++)
                {
                    int dx= x+dirs[i][0];
                    int dy= y+dirs[i][1];
                    
                    if(dx>=0 && dx<N && dy>=0 && dy<M && !vis[dx][dy] && A[dx][dy]==1)
                    {
                        q.push({dx,dy});
                        vis[dx][dy]=1;
                    }
                }
            }
            
            dis++;
        }
        
        return -1;
    }
};
