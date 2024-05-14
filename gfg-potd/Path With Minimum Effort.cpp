You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Example 1:

Input:
row = 3
columns = 3 
heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 
2
Explaination: 
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.
Example 2:

Input:
row = 2
columns = 2 
heights = [[7,7],[7,7]]
Output: 
0
Explaination: 
Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.
Your Task:
You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

Expected Time Complexity: O(rowsxcolumns)
Expected Space Complexity: O(rowsxcolumns)

Constraints:
1 <= rows, columns <= 100
rows == heights.length
columns == heights[i].length
0 <= heights[i][j] <= 106





class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(rows,vector<int> (columns,INT_MAX));
        q.push({0,{0,0}});
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        while(q.size()){
            auto temp = q.front();
            q.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            int dis=temp.first;
            for(int k=0;k<4;k++){
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0 and newj>=0 and newi<rows and newj<columns){
                    int newd = max(dis,abs(heights[i][j]-heights[newi][newj]));
                    if(newd<vis[newi][newj]){
                        vis[newi][newj]=newd;
                        q.push({newd,{newi,newj}});
                    }
                }
            }
        }
        return vis[rows-1][columns-1]!=INT_MAX?vis[rows-1][columns-1]:0;
    }
};
