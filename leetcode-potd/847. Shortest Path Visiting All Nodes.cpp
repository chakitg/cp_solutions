You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.



#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int V = graph.size();
        queue<pair<int, int>> currLevel;
        for (int u = 0; u < V; u++) {
            currLevel.push({u, 1 << u});
        }
        
        int allVisited = (1 << V) - 1;
        vector<vector<bool>> visited(V, vector<bool>(allVisited + 1, false));
        for (int u = 0; u < V; u++) {
            visited[u][1 << u] = true;
        }
        
        int pathLength = 0;
        
        while (!currLevel.empty()) {
            int n = currLevel.size();
            while (n > 0) {
                pair<int, int> node = currLevel.front();
                currLevel.pop();
                int u = node.first;
                int bitMask = node.second;
                
                if (bitMask == allVisited) {
                    return pathLength;
                }
                
                for (int v : graph[u]) {
                    int nextBitMask = bitMask | (1 << v);
                    
                    if (visited[v][nextBitMask]) {
                        continue;
                    }
                    
                    if (nextBitMask == allVisited) {
                        return pathLength + 1;
                    }
                    
                    currLevel.push({v, nextBitMask});
                    visited[v][nextBitMask] = true;
                }
                
                n--;
            }
            
            pathLength++;
        }
        
        return -1;
    }
};
