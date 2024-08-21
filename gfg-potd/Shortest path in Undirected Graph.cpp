You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input:
n = 9, m = 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4

Input:
n = 4, m = 2
edges=[[1,3],[3,0]] 
src=3
Output:
1 1 -1 0

Constraint:
1<=n,m<=104
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)





class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> dist(N, 1e9), ans(N, -1);
        dist[src] = 0;
        unordered_map<int, list<int>> adj;

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(dist[node]+1 < dist[it])
                {
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }

        for(int i = 0; i<N; i++)
        {
            if(dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};
