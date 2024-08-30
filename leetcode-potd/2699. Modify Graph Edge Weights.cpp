You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 

Example 1:



Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
Example 2:



Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
Example 3:



Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
 

Constraints:

1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 or 1 <= wi <= 107
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 109
The graph is connected, and there are no self-loops or repeated edges







class Solution {
public:
    const int INF = 2e9;
    int dijkstra(int n, int src, int dest, vector<pair<int,int>>adj[]){
        vector<int>dist(n,1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [dis, node] = pq.top(); pq.pop();
            if(node == dest) break;
            for(auto it : adj[node]){
                int neighdist = it.second, neighnode=it.first;
                if(dis+neighdist < dist[neighnode]){
                    dist[neighnode] = dis+neighdist;
                    pq.push({dist[neighnode], neighnode});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>>adj[n];
        for(auto it : edges){
            int u=it[0], v=it[1], wt=it[2];
            if(wt == -1) continue;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int shortestpath = dijkstra(n,src,dest,adj);
        if(shortestpath < target) return {};
        bool isequal = (shortestpath == target);
        for(auto &it : edges){
            // int u=it[0], v=it[1], wt=it[2];
            if(it[2] != -1) continue;

            it[2] = isequal ? INF : 1;
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});

            if(!isequal){
                int newshortestpath =  dijkstra(n,src,dest,adj);
                if(newshortestpath <= target){
                    isequal = true;
                    it[2] += target-newshortestpath;
                }
            }
        }
        if(isequal) return edges;
        return {};
    }
};
