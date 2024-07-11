You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

Examples :

Input: grid = [1, 1]
             [0, 1]
Output: 4
Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
[1, 1]
[1, 1]
Input: grid = [1, 0, 1]
             [1, 0, 1]
             [1, 0, 1]
Output: 7
Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
[1, 0, 1]
[1, 0, 1]
[1, 1, 1]
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= size of the grid<= 500
0 <= grid[i][j] <= 1








int dfs(int i, int j, int n, int islandNo, vector<vector<int>>& grid){
       if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || grid[i][j]==islandNo){
           return 0;
       } 
       grid[i][j]=islandNo;
       int a=dfs(i-1, j, n, islandNo, grid);
       int b=dfs(i, j-1, n, islandNo, grid);
       int c=dfs(i+1, j, n, islandNo, grid);
       int d=dfs(i, j+1, n, islandNo, grid);
       return 1+a+b+c+d;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int islandNo=2;
        int n=grid.size();
        unordered_map<int, int>mpp;
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int sz=dfs(i, j, n, islandNo, grid);
                    mpp[islandNo]=sz;
                    ans=max(ans, sz);
                    islandNo++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                unordered_set<int>st;
                int maxS=0;
                if(grid[i][j]==0){
                    if(i>0) st.insert(grid[i-1][j]);
                    if(j>0) st.insert(grid[i][j-1]);
                    if(j<n-1) st.insert(grid[i][j+1]);
                    if(i<n-1) st.insert(grid[i+1][j]);

                    for(auto &it:st){
                        if(mpp.find(it)!=mpp.end()){
                            maxS+=mpp[it];
                        }
                    }
                    maxS+=1;
                    ans=max(maxS, ans);
                }
            }
        }
        return ans;
    }
