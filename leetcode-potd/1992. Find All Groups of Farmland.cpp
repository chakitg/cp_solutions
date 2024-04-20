You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

 

Example 1:


Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
Example 2:


Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
Example 3:


Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.
 

Constraints:

m == land.length
n == land[i].length
1 <= m, n <= 300
land consists of only 0's and 1's.
Groups of farmland are rectangular in shape.





class Solution {
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    #define pb push_back

    void bfs(int r1, int c1, vector<vector<bool>>& vis, vector<vector<int>>& land, int n, int m, vector<vector<int>>& group) {
        vis[r1][c1] = true;

        queue<pair<int,int>> q;
        
        pair<int,int> p = make_pair(r1, c1);

        q.push(p);

        // initialising ending co-ordinates with the starting co-ordinates because it is possible that the starting one only is the ending one
        int r2 = r1 , c2 = c1;

        // i somehow need the last ending co-ordinates
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(auto& d : dir) {
                int newRow = x + d[0];
                int newCol = y + d[1];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m) {
                    if(land[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        pair<int,int> p = make_pair(newRow, newCol);
                        q.push(p);

                        r2 = max(r2, newRow);   
                        c2 = max(c2, newCol);
                        //why max? because the ending points' coordinates will obviously be greater than the starting coordinates as we keep exploring downwards/towards right/left/ upwards
                    }
                }
            }
        }
        
        group.pb({r1, c1, r2, c2});
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // 0 -> forested land
        // 1 -> farmland
        vector<vector<int>> group;

        int n = land.size() , m = land[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && land[i][j] == 1) {
                    bfs(i, j, vis, land, n, m, group);
                }
            }
        }

        return group;
    }
};
