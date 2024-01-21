Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.

Example 1:

Input:
N=5
M=6
edges[][]={{1,2}
           {4, 1},
           {2, 4},
           {3, 4},
           {5, 2},
           {1, 3}}
Output:
3
Explanation:
{2, 3, 4} forms a vertex cover
with the smallest size.
Example 2:

Input:
N=2
M=1
edges[][]={{1,2}} 
Output: 
1 
Explanation: 
Include either node 1 or node 2
in the vertex cover.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible vertex cover.

Expected Time Complexity: O(M*2N)
Expected Auxiliary Space: O(N2)

 Constraints:
1 <= N <= 16
1 <= M <= N*(N-1)/2
1 <= edges[i][0], edges[i][1] <= N




class Solution {
public:
    void solve(int i, int bits, int n, int m, vector<pair<int, int>>& edges, int &out) {
        if (i > n) {
            for (int i = 0; i < m; i++) {
                if (!((1 << (edges[i].first - 1) & bits) != 0 || (1 << (edges[i].second - 1) & bits) != 0)) {
                    return;
                }
            }
            out = min(out, __builtin_popcount(bits));
            return;
        }
        solve(i + 1, bits, n, m, edges, out);
        solve(i + 1, bits | 1 << (i - 1), n, m, edges, out);
    }

    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int out = INT_MAX;
        int m = edges.size();
        solve(1, 0, n, m, edges, out);
        return out;
    }
};
