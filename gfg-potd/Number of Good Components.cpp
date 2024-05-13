Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is fully connected.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 

Example 1:

Input: 


e=3 
v=3
edges={{1, 2},{1, 3},{3, 2}}
Output: 
1
Explanation: 
We can see that there is only one component in the graph and in this component there is a edge between any two vertces.
Example 2:

Input:

e=5 
v=7
edges={{1, 2},{7, 2},{3, 5},{3, 4},{4, 5}}
Output: 
2
Explanation: 
We can see that there are 3 components in the graph. For 1-2-7 there is no edge between 1 to 7, so it is not a fully connected component. Rest 2 are individually fully connected component.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findNumberOfGoodComponent(), which takes an integer e and v and edges[][] as input parameters and returns an integer denoting the number of good components.

Expected Time Complexity: O(v+e)
Expected Auxiliary Space: O(depth of the graph)

Constraints:
1 <= edges[i][0], edges[i][1] <= v
1 ≤ v, e ≤ 104






class Solution {
    public:
    int dfs(vector<int>* adj,int node,vector<int>& visited,int& num)
    {
        int numNode=1;
        visited[node]=num;
        for(auto& it:adj[node])
        {
            if(visited[it]==0)
            numNode+=dfs(adj,it,visited,num);
        }
        return numNode;
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {

        //making adj list
        vector<int> adj[v+1];
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //finding connected components
        vector<int> visited(v+1,0);
        unordered_map<int,int> nodeMap;
        int num=1;
        for(int i=1;i<=v;i++)
        {
            if(visited[i]==0)
            {
                int nodeCnt=dfs(adj,i,visited,num);
                nodeMap[num]=nodeCnt;
                num++;
            }
        }

        //calculating number of good components
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=1;i<=v;i++)
        {
            if(mp.count(visited[i])==0)
            {
                if((adj[i].size()+1)==nodeMap[visited[i]])
                {
                    cnt++;
                    mp[visited[i]]=adj[i].size();
                }
                else
                mp[visited[i]]=-1;
            }
            else
            {
                if(mp[visited[i]]==-1)
                continue;

                if((adj[i].size()+1)!=nodeMap[visited[i]])
                {
                    cnt--;
                    mp[visited[i]]=-1;
                }
            }
        }
        return cnt;
    }
};
