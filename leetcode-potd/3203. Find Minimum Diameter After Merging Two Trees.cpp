There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.

 

Example 1:

Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

Output: 3

Explanation:

We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.

Example 2:


Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

Output: 5

Explanation:

We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.

 

Constraints:

1 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.




class Solution {
public:
    pair<int,int> bfs(int src,int n,vector<vector<int>> &adj)
        {
            int d = 0;
            queue<pair<int,int> > q;
            q.push({src, 0});
            vector<bool> vis(n, false);
            pair<int,int>  u;

            while(!q.empty()) {
                u = q.front();
                q.pop();
                vis[u.first] = true;
                for(int v: adj[u.first])
                    if(!vis[v])
                    q.push({v, u.second + 1});
            }
            return u;
        }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n=e1.size()+1;
        int m=e2.size()+1;
        vector<vector<int>> adj1(n+1),adj2(m+1);
        for(vector<int>&e:e1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        
        pair<int,int>  p1 = bfs(0,n,adj1);
	    pair<int,int>  p2 = bfs(p1.first,n,adj1);
        int l1=(p2.second+1)/2;
        
        for(vector<int>&e:e2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        pair<int,int>  q1 = bfs(0,m,adj2);
	    pair<int,int>  q2 = bfs(q1.first,m,adj2);
        int l2=(q2.second+1)/2;

        return max(l1+l2+1,max(q2.second,p2.second));   
    }
};
