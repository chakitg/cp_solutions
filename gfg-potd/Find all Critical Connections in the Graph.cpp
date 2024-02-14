A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input:

Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.
Example 2:

Input:

Output:
2 3
Explanation:
The edge between nodes 2 and 3 is the only
Critical connection in the given graph.
Your task:
You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters and returns  a list of lists containing the Critical connections in the sorted order.

Expected Time Complexity: O(v + e)
Expected Auxiliary Space: O(v)

Constraints:
1 ≤ v, e ≤ 104




class Solution {
public:
    int timer = 0;
    vector<vector<int>> ans;
    vector<int> vis, dis, low;

    void dfs(int node, int parent, vector<int> adj[]) {
        ++timer;
        vis[node] = 1;
        dis[node] = low[node] = timer;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            else if (!vis[it])
                dfs(it, node, adj);

            low[node] = min(low[node], low[it]);
            if (low[it] > dis[node])
                ans.push_back({min(it, node), max(it, node)});
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vis = vector<int>(v, 0);
        dis = low = vector<int>(v, -1);
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0)
                dfs(i, -1, adj);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
