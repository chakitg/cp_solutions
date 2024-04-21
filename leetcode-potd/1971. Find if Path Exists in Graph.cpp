There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.





class Solution {
public:
    // Recursive DFS function to explore the graph
    void dfs(int vertex, vector<vector<int>>& graph, vector<int>& vis) {
        vis[vertex] = 1; // Mark the current vertex as visited
        // Iterate over all adjacent vertices (children)
        for (auto child : graph[vertex]) {
            if (!vis[child]) { // If the child vertex has not been visited
                dfs(child, graph, vis); // Recursively visit the child
            }
        }
    }

    // Function to check if there's a valid path between source and destination
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n); // Adjacency list for the graph
        vector<int> vis(n, 0); // Visited array to keep track of visited vertices, initialized to 0
        
        // Building the graph from the edge list
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]); // Add an edge from vertex edges[i][0] to edges[i][1]
            graph[edges[i][1]].push_back(edges[i][0]); // Since the graph is undirected, add the reverse edge as well
        }

        // Start DFS from the source vertex
        dfs(source, graph, vis);

        // Check if the destination vertex has been visited
        return vis[destination] == 1;
    }
};
