You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.



class Solution {
public:

    int findparent(int x, vector <int>& parent){
          while(x != parent[x]) x = parent[x];
          return x;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
            
            int  n = points.size();
            vector <vector <int>> adj;

            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){

                    int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                    int distance = abs(x1 - x2) + abs(y1 - y2);

                    adj.push_back({distance, i, j});
                   
                }
            }

            sort(adj.begin(), adj.end());
            vector <int> parent(n);

            for(int i = 0; i < n; i++){
                parent [i] = i;
            }
            
            int sum = 0;

            for(int i = 0; i < adj.size(); i++){
                int x = adj[i][1];
                int y = adj[i][2];

                x = findparent(x, parent);
                y = findparent(y, parent);

                if(x != y){
                    parent[y] = x;
                    sum += adj[i][0]; 
               }
            }

            return sum;

    }
};
