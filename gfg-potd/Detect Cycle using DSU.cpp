Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

Note: Solve the problem using disjoint set union (DSU).

Example 1:

Input: 

Output: 1
Explanation: There is a cycle between 0->2->4->0
Example 2:

Input: 

Output: 0
Explanation: The graph doesn't contain any cycle
Your Task:
You don't need to read or print anyhting. Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list adj and returns 1 if graph contains any cycle otherwise returns 0.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ 104




class Solution {
public:
    vector<int> dsu;
    vector<bool> vis;
    vector<set<int>> g;

    int findDSU(int p) {
        if (dsu[p] < 0)
            return p;
        return dsu[p] = findDSU(dsu[p]);
    }

    void merge(int x, int y) {
        if (dsu[x] > dsu[y])
            swap(x, y);

        dsu[x] += dsu[y];
        dsu[y] = x;
    }

    bool dfs(int node, int par) {
        bool isCycle = false;
        vis[node] = true;

        for (auto child : g[node]) {
            if (child != par) {
                int x = findDSU(node);
                int y = findDSU(child);

                if (x == y)
                    return true;

                merge(x, y);
                isCycle = isCycle || dfs(child, node);
            }
        }

        return isCycle;
    }

    int detectCycle(int V, vector<int> adj[]) {
        dsu = vector<int>(V, -1);
        vis = vector<bool>(V, false);
        g = vector<set<int>>(V);

        for (int i = 0; i < V; i++) {
            for (auto x : adj[i])
                g[i].insert(x);
        }

        bool isCycle = false;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                isCycle = isCycle || dfs(i, -1);
        }

        return isCycle;
    }
};
